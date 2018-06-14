#pragma once
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

#include "graph.h"
#include "heap.h"

#ifndef __MAIN_H__
#define __MAIN_H__

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#ifdef _WIN32
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

/**
 * @brief 		데이터 폴더로부터 그래프를 입력받아 초기화 후 반환해주는 함수 
 * 
 * @param data_folder 
 * @return graph* 
 */
graph* read_graph(const char* data_folder){
	int i;
	char input_path[1024];
	FILE * fin;
	int V, E;
	graph* g;

	sprintf(input_path, "%s%s%s", data_folder, PATH_SEPARATOR, INPUT_FILE_NAME);
	fin = fopen(input_path, "r");

	fscanf(fin, "%d %d", &V, &E);
	g = init_graph(V, E);
	for (i = 0; i < E; i += 1){
		int org, dest, weight;
		fscanf(fin, "%d %d %d", &org, &dest, &weight);
		g->edges[i] = (edge){ i, org, dest, weight };
	}

	fclose(fin);

	return g;
}

/**
 * @brief 
 * 
 * @param data_folder 
 * @param g 
 */
void write_graph(const char* data_folder, graph* g){
	int i;
	int sum = 0;
	char output_path[1024];
	FILE * fout;
	sprintf(output_path, "%s%s%s", data_folder, PATH_SEPARATOR, OUTPUT_FILE_NAME);
	fout = fopen(output_path, "w+");

	fprintf(fout, "%d %d\n", g->V, g->E);

	for (i = 0; i < g->E; i += 1){
		fprintf(fout, "%d %d %d\n", g->edges[i].origin, g->edges[i].dest, g->edges[i].weight);
		sum += g->edges[i].weight;
	}

	fprintf(fout, "WEIGHT SUM : %d\n", sum);
	fclose(fout);
}

#endif