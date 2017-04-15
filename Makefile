CC=gcc
SRC=./src/*
INCLUDE=./include
#BINARIES=

all:
	$(CC) -I $(INCLUDE) $(SRC)

#debug:

clear:
	rm $(BINARIES)
