CC=gcc
#CFLAGS = -g -Wall					
SRC=./src/
OBJECTS = main.c
INCLUDE=./include/
#BINARIES=
# OBS: "OBJECTS" used since otherwise gcc tries do compile backup file (main.c~, etc).

all:
	$(CC) $(CFLAGS) -I $(INCLUDE) $(SRC)$(OBJECTS) -o trabalho

run:
	./trabalho
	
	
############ FOR DEBUGGIN ONLY, REMOVE LATER ############ 
# Remove "-g" from CFLAGS, only necessary for valgrind.
# VALFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

val:
	valgrind $(VALFLAGS) ./trabalho

clear:
	rm $(BINARIES)
