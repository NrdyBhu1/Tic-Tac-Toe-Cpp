#include <iostream>
#include <string>
#include "./colors.hpp"
#include <stdlib.h>
#include <regex>

using namespace std;

bool isNumber(std::string x)
{
  std::regex e ("^-?\\d+");
  if (std::regex_match (x,e)) return true;
  else return false;
}

auto board =
  {
    "/",
    "-",    "-",    "-",
    "-",    "-",    "-",
    "-",    "-",    "-",
    "/"
  };
int playerMove = 0;

void UpdateBoard()
{
  cout << BOLDCYAN << "Tic Tac Toe" << RESET << endl;
  cout << "-------" << endl;
  cout << "|" << board[1] << "|" << board[2] << "|" << board[3] << "|" << endl;
  cout << "-------" << endl;
  cout << "|" << board[4] << "|" << board[5] << "|" << board[6] << "|" << endl;
  cout << "-------" << endl;
  cout << "|" << board[7] << "|" << board[8] << "|" << board[9] << "|" << endl;
  cout << "-------" << endl;
}

bool validatePlayerMove(int move)
{
  return board[move] == "-" && move > 0 && move < 10;
}

int main() 
{
  // Do not move
  system("title Tic-Tac-Toe");
  system("cls");

  bool gameOver = false;
  string input;
  while(!gameOver)
    {
      UpdateBoard(); 
      cin >> input;
      if (input == "end")
	{
	  gameOver = true;
	}else
	{
	  if(isNumber(input))
	    {
	      cout << RED << "Not a valid input `" << input << "`" << RESET << endl; 
	    }else
	    {
	      playerMove = stoi(input);
	      if (validatePlayerMove(playerMove))
		{
		  cout << RED << "Not a valid playerMove `" << playerMove << "`" << RESET << endl;
		}
	    }
	}
    }
  //Return 0
  return 0;
}
