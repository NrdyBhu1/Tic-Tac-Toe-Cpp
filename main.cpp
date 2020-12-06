#include <iostream>
#include "COLORS.h"
#include <stdlib.h>

std::string tictactoeArr[18] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

void processCmd(std::string comd){
	int nm = std::atoi(comd.c_str());
	if(nm < 10 && tictactoeArr[nm-1] != "X" && tictactoeArr[nm-1] != "O"){
		tictactoeArr[nm-1] = "X";
	}else{
		std::cout << "Please enter a valid number";
	}
}

void updateBoard(){
	system("cls");
	std::cout << BOLDCYAN << "TIC TAC TOE" << RESET << std::endl;
	std::cout << tictactoeArr[0] << "|" << tictactoeArr[1] << "|" << tictactoeArr[2] << std::endl;
	std::cout << "-" << " - " << "- " << std::endl;
	std::cout << tictactoeArr[3] << "|" << tictactoeArr[4] << "|" << tictactoeArr[5] << std::endl;
	std::cout << "-" << " - " << "- " << std::endl;
	std::cout << tictactoeArr[6] << "|" << tictactoeArr[7] << "|" << tictactoeArr[8] << std::endl;
	std::cout << " " << std::endl;
}

int main(int argc, char** argv) {
	// Do not move
	system("title Tic Tac Toe");
	system("cls");

	//Code
	std::string cmd = "";
	while (cmd != "end"){
		updateBoard();
		std::cout << ">:";
		std::cin >> cmd;
		processCmd(cmd);
	}
	//Return 0
	return 0;
}
