CC = gcc
FLAGS = -Wall -g
AR = ar

all: graph


graph: main.o graphlib.a
	$(CC) $(FLAGS) -o graph main.o graphlib.a

main.o: main.c graph.h 
	$(CC) $(FLAGS) -c main.c 

dijkstra.o: dijkstra.c graph.h
	$(CC) $(FLAGS) -c dijkstra.c

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

graphlib.a: dijkstra.o graph.o
	$(AR) -rcs graphlib.a dijkstra.o graph.o

.PHONY: clean all
clean: 
	rm -f *.o *.a graph



