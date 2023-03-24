#include"formulas.h"

char set_bw_color(char red, char green, char blue) {
	char bw = (char)(red * 0.3 + green * 0.59 + blue * 0.11);
	return bw;
}