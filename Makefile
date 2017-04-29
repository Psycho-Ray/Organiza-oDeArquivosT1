################################ VARIABLES ####################################

CC=gcc
CFLAGS = -g -Wall
# Add the files that need to be compiled, like: src/file_name.c
SRCS= src/main.c
INCLUDE=./include
EXEC=trabalho

###############################################################################

all: compile

compile:
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SRCS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)
	
	
############ FOR DEBUGGIN ONLY, REMOVE LATER ############ 
# Remove "-g" from CFLAGS, only necessary for valgrind.
# VALFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

val: $(EXEC)
	valgrind $(VALFLAGS) ./$(EXEC)

clean:
	rm $(EXEC)
