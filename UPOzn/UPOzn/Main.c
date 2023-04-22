#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "morse.h"
#include "resources.h"
#include "log.h"

int main() {
	printf("----- MORSE-CODER -----\n");
	
	FILE* logbook = file_create("logbook.txt");

	push_log(logbook, "app", "Programm runs.");

	menu();

	fclose(logbook);

	push_log(logbook, "app", "Programm ends.");

	return 0;
}