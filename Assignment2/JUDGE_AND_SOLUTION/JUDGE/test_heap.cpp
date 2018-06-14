#include "main.h"
#include "graph.h"
#include "heap.h"

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<memory.h>


int main(int argc, char *argv[]){
	int i;
	int j;
    char DATA_FOLDER[2048];

    strcpy(DATA_FOLDER, argv[1]);

	graph* g = read_graph(DATA_FOLDER);
	heap_sort(g->edges, g->E);
	write_graph(DATA_FOLDER, g);

    release_graph(g);
	return 0;
}