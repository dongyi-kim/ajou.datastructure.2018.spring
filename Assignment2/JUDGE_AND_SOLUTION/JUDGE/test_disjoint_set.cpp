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
	disjoint_set* set = init_set(g->V);
	graph* spanning_tree = init_graph(g->V, g->V - 1);

	for (i = 0, j = 0; i < g->E; i += 1){
		int u = g->edges[i].origin;
		int v = g->edges[i].dest;


		if (find_set(set, u) == find_set(set, v)){
			continue;
		}

		spanning_tree->edges[j++] = g->edges[i];

		union_set(set, u, v);
	}

	write_graph(DATA_FOLDER, spanning_tree);

	release_set(set);
    release_graph(g);
    release_graph(spanning_tree);
	return 0;
}