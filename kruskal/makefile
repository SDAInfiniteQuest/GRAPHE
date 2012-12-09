OBJ=obj/
SRC=src/
BIN=bin/
INC=-Iinclude
VPATH=src:include:bin
CC=gcc
CFLAGS= -Wall -g -lm  

ALL: exo1 

exo1:exo1.o matrix.o table.o quicksort.o kruskal.o 
	$(CC) -o $(BIN)$@ $(OBJ)exo1.o $(OBJ)matrix.o $(OBJ)table.o $(OBJ)quicksort.o $(OBJ)kruskal.o $(CFLAGS)

exo1.o:exo1.c matrix.h
	$(CC) -c $< $(INC) -o $(OBJ)$@ $(CFLAGS)

matrix.o:matrix.c matrix.h 
	$(CC) -c $< $(INC) -o $(OBJ)$@ $(CFLAGS)

table.o:table.c table.h 
	$(CC) -c $< $(INC) -o $(OBJ)$@ $(CFLAGS)

quicksort.o:quicksort.c quicksort.h table.h
	$(CC) -c $< $(INC) -o $(OBJ)$@ $(CFLAGS)

kruskal.o:kruskal.c kruskal.h quicksort.h
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
	rm -r obj/*.o bin/exo1 DocDoxy

doxy:
	doxygen

