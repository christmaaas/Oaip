
#include "lru.h"
#include "cache.h"
#include "hashtable.h"
#include "resources.h"

int database_search(const char* key, char** domain, char** ip) {
	char* string = (char*)malloc(MAX_SIZE_OF_STRING);
	char* domain_name = (char*)malloc(MAX_SIZE_OF_STRING);
	char* ip_adress = (char*)malloc(MAX_SIZE_OF_STRING);

	int index = 0;
	int indent_accumulator = 0;
	int indent = 0;
	int domain_type = 0;

	FILE* file = file_open("database.txt", "r");

	while (!feof(file)) {

		fgets(string, MAX_SIZE_OF_STRING, file);

		index = find_pattern(string, "IN A");
		indent = IN_A;
		domain_type = TYPE_A;

		if (index == NOT_FOUNDED) {
			index = find_pattern(string, "IN CNAME");
			indent = IN_CNAME;
			domain_type = TYPE_CNAME;
		}

		fseek(file, 0 + indent_accumulator, SEEK_SET);
		fgets(domain_name, index - indent, file);

		fseek(file, index + indent_accumulator + INDENT_FOR_SPACE, SEEK_SET);
		fgets(ip_adress, MAX_SIZE_OF_STRING, file);

		indent_accumulator += strlen(string) + INDENT_FOR_NEWLINE;

		if (!strcmp(key, domain_name)) {
			(*domain) = domain_name;
			(*ip) = ip_adress;
			(*ip)[strcspn((*ip), "\n")] = NULL_TERMINATOR;

			fclose(file);

			free(string);

			return domain_type;
		}

	}

	free(string);
	free(domain_name);
	free(ip_adress);

	fclose(file);

	return NOT_FOUNDED;
}

char* cache_search(lru_cache* cache, const char* key, int flag) {
	char* check = NULL;
	char* cache_search_result = NULL;
	char* hashtable_search_result = hashtable_search(cache->table, key);

	if (hashtable_search_result != NULL) {
		if (valid_ip_check(hashtable_search_result) == RIGHT_IP_ADRESS && flag == TYPE_A_SEARCH) {
			printf("\nHIT\n");

			return hashtable_search_result;
		}
		else {
			return hashtable_search_result;
		}
	}
	else {
		if (flag == TYPE_A_SEARCH)
			printf("\nMISS\n");

		char* domain = NULL;
		char* ip_adress = NULL;

		int database_search_result = database_search(key, &domain, &ip_adress);

		if (database_search_result == NOT_FOUNDED) {
			printf("\nError. No such domen on dns server\n");
			printf("Create new domain and IP-adress:\n");

			add_database(key);

			return NULL;
		}
		else if (database_search_result == TYPE_CNAME) {
			flag = TYPE_CNAME_SEARCH;

			if ((cache_search_result = cache_search(cache, ip_adress, flag)) != NULL) {
				cache_insert(cache, key, cache_search_result);

				free(domain);
				free(ip_adress);

				return cache_search_result;
			}
		}
		else if (flag == TYPE_CNAME_SEARCH) {
			return ip_adress;
		}
		else {
			cache_insert(cache, domain, ip_adress);
			
			free(domain);
			
			return ip_adress;
		}
	}

	return NULL;
}

void add_database(const char* domen) {
	FILE* database = file_open("database.txt", "r+");
	char* new_info = NULL;

	fseek(database, 0, SEEK_END);
	fprintf(database, "%s", domen);

	printf("\nPick a type of \"%s\" :\n", domen);
	printf("--------------\n");
	printf("1 - \"IN A\"\n", domen);
	printf("2 - \"IN CNAME\"\n", domen);
	printf("--------------\n");
	printf("Your choice: ");

	int choice = choice_domen_type();

	if (choice == TYPE_A) {
		fprintf(database, "%s", " IN A ");

		printf("\nInput IP-adress: ");

		new_info = input_str();
		while (valid_ip_check(new_info) == WRONG_INPUT) {
			printf("\nWrong input try again: ");

			free(new_info);

			new_info = input_str();
		}
	}
	else if (choice == TYPE_CNAME) {
		fprintf(database, "%s", " IN CNAME ");

		printf("\nInput domain: ");

		new_info = input_str();
	}

	fprintf(database, "%s\n", new_info);

	printf("\n");

	fclose(database);
}

void ip_search_by_domain(lru_cache* cache) {
	char* cache_search_result = NULL;
	char* domain_name = NULL;

	printf("\nInput a domain: ");

	domain_name = input_str();

	cache_search_result = cache_search(cache, domain_name, TYPE_A_SEARCH);

	if (cache_search_result != NULL)
		printf("Searched IP-adress: %s\n", cache_search_result);

	free(cache_search_result);
}

void domain_search_by_ip() {
	char* buffer = (char*)malloc(MAX_SIZE_OF_STRING);
	char* domain = (char*)calloc(MAX_SIZE_OF_STRING, 1);
	char* ip_adress = (char*)calloc(MAX_SIZE_OF_STRING, 1);

	int flag = 0;

	printf("\nEnter IP-adress: ");

	char* searche = input_str();
	if (valid_ip_check(searche) != RIGHT_IP_ADRESS) {
		printf("\nWrong IP-adress\n");

		free(buffer);
		free(domain);
		free(ip_adress);
		free(searche);

		return;
	}

	printf("\n--- DOMENS ---\n");

	FILE* database = file_open("database.txt", "r");

	while (!feof(database)) {
		fgets(buffer, MAX_SIZE_OF_STRING, database);
		int len = strcspn(buffer, "\n");

		buffer[len] = NULL_TERMINATOR;

		if (sscanf(buffer, "%s IN A %s", domain, ip_adress) == 2 && flag == ORIGINAL_DOMAIN_NOT_FOUNDED) {
			if (!strcmp(searche, ip_adress)) {
				printf("%s\n", domain);

				flag = ORIGINAL_DOMAIN_FOUNDED;

				searche = realloc(searche, strlen(domain) + 1);
				strcpy_s(searche, strlen(domain) + 1, domain);
			}
		}
		if (sscanf(buffer, "%s IN CNAME %s", domain, ip_adress) == 2 && flag == ORIGINAL_DOMAIN_FOUNDED) {
			if (!strcmp(searche, ip_adress))
				printf("%s\n", domain);

		}
	}

	free(buffer);
	free(domain);
	free(ip_adress);
	free(searche);

	if (flag == ORIGINAL_DOMAIN_NOT_FOUNDED) {
		printf("\nNo one domain is dounded\n");

		return;
	}
	else {
		printf("-----------------\n");
	}
}