#include <iostream>
#include "COLORS.h"
#include <stdlib.h>
#include <regex>

bool isNumber(std::string x){
    std::regex e ("^-?\\d+");
    if (std::regex_match (x,e)) return true;
    else return false;
}

int main() {
	// Do not move
	system("title Tic Tac Toe");
	system("cls");
	
	//Return 0
	return 0;
}
