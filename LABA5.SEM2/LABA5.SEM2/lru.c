
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

			//add_database(key);

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

char* valid_ip_input() {
	char* ip_adress = input_str();
	
	while (ip_adress[3] != '.' && ip_adress[7] != '.' && ip_adress[11] != '.' && 
		(atoi(ip_adress[0]) <= 2) && (atoi(ip_adress[1]) <= 5) && (atoi(ip_adress[2]) <= 5) && 
		(atoi(ip_adress[4]) <= 2) && (atoi(ip_adress[5]) <= 5) && (atoi(ip_adress[6]) <= 5) && 
		(atoi(ip_adress[8]) <= 2) && (atoi(ip_adress[9]) <= 5) && (atoi(ip_adress[10]) <= 5) && 
		ip_adress[14] != '\0') {
		
		printf("\nWrong IP-adress input.\n");

		free(ip_adress);

		ip_adress = input_str();
	}
	
	return ip_adress;
}

void add_database(char* domen) {
	FILE* database = file_open2("database.txt");
	
	fprintf(database, "%s", domen);
	
	printf("\nPick a type of %s :\n", domen);
	printf("1 - A\n", domen);
	printf("2 - CNAME\n", domen);
	printf("Your choice: ");
	
	int choice = choice_domen_type();

	if (choice == A) {
		fprintf(database, "%s", " A ");
	}
	else if(choice == CNAME) {
		fprintf(database, "%s", " CNAME ");
	}

	char* ip_adress = valid_ip_input();
	
	fprintf(database, "%s\n", ip_adress);

	fclose(database);
}
