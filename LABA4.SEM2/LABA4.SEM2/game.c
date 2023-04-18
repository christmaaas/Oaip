#include "game.h"
#include "tree.h"
#include "log.h"
#include "resources.h"

int pick_answer() {
	int pick = 0;
	
    while (scanf_s("%d", &pick) == 0 || pick < 1 || pick > 2 || getchar() != '\n') {
		printf("\nYou need to pick 1 or 2: ");
		rewind(stdin);
	}
	
    return pick;
}

char* input_str() {
	char* string = (char*)calloc(STRING_SIZE, sizeof(char));
	
    gets_s(string, STRING_SIZE);
	
    int size = strlen(string);
	
    string = (char*)realloc(string, size + 1);
	
    return string;
}

void print_answer_menu() {
	printf("----------------\n");
	printf("1 - Yes | 2 - No\n");
	printf("----------------\n");
	printf("Your answer: ");
}

void new_game() {
    FILE* database_file = NULL;
    FILE* log_file = NULL;

    node* temp = NULL;
    node* first_question = NULL;

    log_file = file_create("logbook.txt");

    push_log(log_file, "Program run.", "app");
    push_log(log_file, "Game was started.", "game");

    if ((database_file = file_open("database.txt")) == NULL) {
        first_question = get_new_node("Cristiano Ronaldo");
        push_log(log_file, "Error to open \"database.txt\" file in \"r\" mode.", "error");
        push_log(log_file, "Object \"Cristiano Ronaldo\" has created.", "game");
    }
    else {
        first_question = load_database(database_file);
        push_log(log_file, "\"database.txt\" was uploaded successfully.", "app");
        fclose(database_file);
    }

    printf("Hello! I am football Akinator! Try to beat me, good luck!\n");

    while (INFINITE_CYCLE) {
        temp = footballer_tree_traversal(log_file, first_question);
        if (temp == NULL) {
            break;
        }
        add_new_footballer(log_file, temp);
    }

    printf("\nThanks for game! Come back and play again!\n");

    push_log(log_file, "Game was ended.", "game");

    database_file = file_create("database.txt");

    push_database(database_file, first_question);

    fclose(database_file);

    push_log(log_file, "\"database.txt\" was saved.", "app");
    push_log(log_file, "Program finished.", "app");

    fclose(log_file);

    free_tree(first_question);
}
