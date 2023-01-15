CC = gcc
FLAGS = -Wall -g

all: graph

graph: main.o algo.o nodes.o edges.o
	$(CC) $(FLAGS) -o graph main.o algo.o nodes.o edges.o

main.o: main.c algo.h graph.h
	$(CC) $(FLAGS) -c main.c

algo.o: algo.c  nodes.h edges.h algo.h graph.h
	$(CC) $(FLAGS) -c algo.c

nodes.o: nodes.c nodes.h graph.h
	$(CC) $(FLAGS) -c nodes.c

edges.o: edges.c  edges.h graph.h
	$(CC) $(FLAGS) -c edges.c







.PHONY: clean all

clean:
	rm -f *.o graph