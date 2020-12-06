#include <iostream>
#include "COLORS.h"
#include <stdlib.h>
#include <regex>

bool isNumber(std::string x){
    std::regex e ("^-?\\d+");
    if (std::regex_match (x,e)) return true;
    else return false;
}

bool endGame = false;
std::string tictactoeArr[18] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

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

bool checkHor(){
	if (tictactoeArr[0] == tictactoeArr[1] && tictactoeArr[1] == tictactoeArr[2]){
		return true;
	}else if (tictactoeArr[3] == tictactoeArr[4] && tictactoeArr[4] == tictactoeArr[5]){
		return true;
	}else if (tictactoeArr[6] == tictactoeArr[7] && tictactoeArr[7] == tictactoeArr[8]){
		return true;
	}else{
		return false;
	}
}

bool checkVer(){
	if (tictactoeArr[0] == tictactoeArr[3] && tictactoeArr[3] == tictactoeArr[6]){
		return true;
	}else if (tictactoeArr[1] == tictactoeArr[4] && tictactoeArr[4] == tictactoeArr[7]){
		return true;
	}else if (tictactoeArr[2] == tictactoeArr[5] && tictactoeArr[5] == tictactoeArr[8]){
		return true;
	}else{
		return false, "none";
	}
}

bool checkDiagonals(){
	if (tictactoeArr[0] == tictactoeArr[4] && tictactoeArr[4] == tictactoeArr[8]){
		return true;
	}else if (tictactoeArr[2] == tictactoeArr[4] && tictactoeArr[4] == tictactoeArr[6]){
		return true;
	}else{
		return false;
	}
}

void checkWinners(){
	bool Diag = checkDiagonals();
	bool Hor = checkHor();
	bool Ver = checkVer();
	if(Diag && !Hor && !Ver){
		endGame = true;
		std::cout << YELLOW << tictactoeArr[4]+" is the winner" << RESET << std::endl;
	}else if(!Diag && Hor && !Ver){
		endGame = true;
		std::cout << YELLOW << tictactoeArr[4]+" is the winner" << RESET << std::endl;
	}else if(!Diag && !Hor && Ver){
		endGame = true;
		std::cout << YELLOW << tictactoeArr[4]+" is the winner" << RESET << std::endl;
	}
}

void processCmd(std::string comd){
	checkWinners();
	if (isNumber(comd)){
		int nm = std::atoi(comd.c_str());
		if(nm < 10 && tictactoeArr[nm-1] != "X" && tictactoeArr[nm-1] != "O"){
			tictactoeArr[nm-1] = "\033[31mX\033[0m";
			updateBoard();
		}else{
			updateBoard();
			std::cout << RED << "Please enter a valid number" << RESET << std::endl;
		}
	}else{
		if (comd == "end"){
			endGame = true;
		}else{
			updateBoard();
			std::cout << RED << "Please enter a valid number" << RESET << std::endl;
		}
	}
}

int main(int argc, char** argv) {
	// Do not move
	system("title Tic Tac Toe");
	system("cls");
	updateBoard();

	//Code
	std::string cmd = "";
	while (!endGame){
		std::cout << ">:";
		std::cin >> cmd;
		processCmd(cmd);
	}
	//Return 0
	return 0;
}
