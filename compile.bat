@echo off

IF NOT EXIST icon.res.o (
    windres icon.rc -o icon.res.o
)

g++ main.cpp -std=c++11 icon.res.o -o TicTacToe.exe

IF EXIST TicTacToe.exe (
    mkdir build
    move TicTacToe.exe build/
)
echo done...
@echo on