################################ VARIABLES ####################################

CC=gcc
CFLAGS = -g -Wall
# Add the files that need to be compiled, like: src/file_name.c
SRCS= src/main.c src/indicadorTamanho/* src/delimitador/*  src/numFixosCampos/* src/utils.c
INCLUDE=./include
EXEC=trabalho
OUTPUT=answer.dat

###############################################################################

all:
	make clear
	make compile

compile:
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SRCS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)


############ FOR DEBUGGING ONLY, REMOVE LATER ############
# Remove "-g" from CFLAGS, only necessary for valgrind.
# VALFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
# just a test

val: $(EXEC)
	valgrind $(VALFLAGS) ./$(EXEC)

clear:
	rm $(EXEC) $(OUTPUT)

# Bruno usa isso
open:
	gedit Makefile $(SRCS) $(include)/*

