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

	graph* spanning_tree;
	graph* graph;
	graph = read_graph(DATA_FOLDER);

	spanning_tree = find_minimum_spanning_tree(graph);

	write_graph(DATA_FOLDER, spanning_tree);

	release_graph(graph);
	release_graph(spanning_tree);

	return 0;
}