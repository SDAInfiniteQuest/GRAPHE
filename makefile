OBJ=obj/
SRC=src/
BIN=bin/
INC=-Iinclude
VPATH=src:include:bin
CC=gcc
CFLAGS= -Wall -g -lm  

ALL: exo1 

exo1:exo1.o generation.o
	$(CC) -o $(BIN)$@ $(OBJ)exo1.o $(OBJ)generation.o $(CFLAGS)

exo1.o:exo1.c generation.h
	$(CC) -c $< $(INC) -o $(OBJ)$@ $(CFLAGS)

generation.o:generation.c generation.h 
	$(CC) -c $< $(INC) -o $(OBJ)$@ $(CFLAGS)


#exo2:exo2.o
#	$(CC) -o $(BIN)$@ $(OBJ)exo1.o  $(CFLAGS)

#exo2.o:exo2.c 
#	$(CC) -c $< $(INC) -o $(OBJ)$@ $(CFLAGS)


#exo3:exo3.o
#	$(CC) -o $(BIN)$@ $(OBJ)exo1.o  $(CFLAGS)

#exo3.o:exo3.c 
#	$(CC) -c $< $(INC) -o $(OBJ)$@ $(CFLAGS)


clean:
	rm -r obj/*.o bin/exo1 bin/exo2 bin/exo3 DocDoxy

doxy:
	doxygen

