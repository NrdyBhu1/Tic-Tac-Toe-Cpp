CC = g++
CFLAGS = c++17 -Wall -Wextra -Wpedantic
FILE = src/main.cpp
OBJ = bin/tic-tac-toe.exe

all install:
	@echo use "\ make debug \" for debug mode	
	@echo use "\ make release \" for release mode

debug: $(FILE)
	$(CC) $(CFLAGS) $(FILE) -o $(OBJ)

release: $(FILE) icon.o
	$(CC) $(CFLAGS) $(FILE) icon.o -o $(OBJ)

icon.o: icon.rc
	windres -i icon.rc -o icon.o

