.PHONY: all clean
CC = gcc
AR = ar
FLAGS= -Wall -Werror -g
all: graph 
graph: main.o graph.a
	$(CC) $(FLAGS) -o graph main.o graph.a
graph.a: graph.o dijkstra.o tsp.o
	$(AR) -rcs graph.a graph.o dijkstra.o tsp.o
main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c
graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c
dijkstra.o: dijkstra.c graph.h
	$(CC) $(FLAGS) -c dijkstra.c
tsp.o: tsp.c graph.h
	$(CC) $(FLAGS) -c tsp.c
clean:
	rm -f *.o *.a graph