
#include "lru.h"
#include "cache.h"
#include "hashtable.h"
#include "resources.h"

int database_search(char* key,char** domain, char** ip) {
	char* string = (char*)malloc(MAX_SIZE_OF_STRING);
	char* domain_name = (char*)malloc(MAX_SIZE_OF_STRING);
	char* ip_adress = (char*)malloc(MAX_SIZE_OF_STRING);

	int index = 0;
	int accumulator = 0;
	int indent = IN_A;
	int domen_type = 0;

	FILE* file = file_open("database.txt");

	while (!feof(file)) {

		if (!strcmp(key, domain_name)) {
			(*domain) = domain_name;
			(*ip) = ip_adress;
			(*ip)[strcspn((*ip), "\n")] = '\0';
			fclose(file);
			return domen_type;
		}
		fgets(string, MAX_SIZE_OF_STRING, file);
		index = find_pattern(string, "IN A");
		indent = IN_A;
		domen_type = A;

		if (index == 0) {
			index = find_pattern(string, "IN CNAME");
			indent = IN_CNAME;
			domen_type = CNAME;
		}

		fseek(file, 0 + accumulator, SEEK_SET);
		fgets(domain_name, index - indent, file);

		fseek(file, index + accumulator + 1, SEEK_SET);
		fgets(ip_adress, MAX_SIZE_OF_STRING, file);       

		accumulator += strlen(string) + 1;            
	}

	fclose(file);
	return 0;
}

char* cache_search(lru_cache* cache, char* key, int flag) {
	char* temp = NULL;
	char* search_result = hashtable_search(cache->table, key);

	if (search_result != NULL) {
		if (flag == 0) {
			printf("\nHIT\n");
		}
		if ((temp = hashtable_search(cache->table, search_result)) == NULL)
			return search_result;
		else
			return temp;
	}
	else {
		if (flag == 0) {
			printf("\nMISS\n");
		}

		char* domain = NULL;
		char* ip =  NULL;

		int database_search_result =  database_search(key, &domain, &ip);

		if (database_search_result == 0)
		{
			printf("\nError. No such domen on dns server\n");
			printf("Create new domain and IP-adress: \n");

			add_database(key);

			return; 
		}
		else if (database_search_result == CNAME)
		{
			flag = 1,
			cache_insert(cache, domain, ip);
			cache_search(cache, ip, flag);
		}
		else
		{
			cache_insert(cache, domain, ip);
			return ip;
		}		
	}
}

int valid_ip_input(char* str) {
	if (str == NULL) {
		return 0;
	}

	int arr[4];
	int counter = sscanf_s(str, "%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]);
	if (counter != 4) {
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		if (arr[i] < 0 || arr[i] > 255) {
			return 0;
		}
	}
	return 1;
}

void add_database(char* domen) {
	FILE* database = file_open2("database.txt");
	
	fseek(database, 0, SEEK_END);
	fprintf(database, "%s", domen);
	
	printf("\nPick a type of %s :\n", domen);
	printf("1 - A\n", domen);
	printf("2 - CNAME\n", domen);
	printf("Your choice: ");
	
	int choice = choice_domen_type();

	if (choice == A) {
		fprintf(database, "%s", " IN A ");
	}
	else if(choice == CNAME) {
		fprintf(database, "%s", " IN CNAME ");
	}

	printf("\nInput ip: \n");

	char* ip_adress = input_str();
	while (valid_ip_input(ip_adress) == 0) {
		printf("\nWrong input try again\n");
		free(ip_adress);
		ip_adress = input_str();
	}
	
	fprintf(database, "%s\n", ip_adress);

	fclose(database);
}
