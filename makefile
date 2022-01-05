# CC = gcc
# AR = ar
# FLAGS = -Wall -g

# all: graph

# main.o: main.c graph.h
# 	$(CC) $(FLAGS) -c main.c

# graph.o: graph.c graph.h
# 	$(CC) $(FLAGS) -c graph.c 

# libgraph.a: graph.o
# 	$(AR) -rcs libgraph.a graph.o

# graph: main.o libgraph.a 
# 	$(CC) $(FLAGS) -o graph main.o libgraph.a 

# .PHONY: clean all
# clean: 
# 	rm -f *.o *.so libgraph.a graph

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



