#pragma once
#pragma warning(disable: 4996)

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#ifndef __GRAPH_H__
#define __GRAPH_H__

typedef struct edge_t edge;
typedef struct vertex_t vertex;
typedef struct graph_t graph;
typedef struct disjoint_set_t disjoint_set;

typedef struct edge_t{
	int index;		// 간선 ID	(0-Based)
	int origin;		// 노드 1
	int dest;		// 노드 2
	int weight;		// 가중치 
};

typedef struct vertex_t{
	int index;		// 노드 ID (0-Based)
};

typedef struct graph_t{
	int V;			// 그래프의 노드 수 
	int E;			// 그래프의 간선 수 
	edge* edges;	// 간선 배열 edges[0] ~ edges[E-1]
};

typedef struct disjoint_set_t {
	int size;		// disjoint set의 크기 
	int *group;		// group[u] := u번 노드가 속한 그룹의 대표 노드 번호
};

int find_set(disjoint_set* set, int u);
void union_set(disjoint_set* set, int u, int v);
graph* find_minimum_spanning_tree(graph* g);

/**
* @brief 		그래프의 크기를 입력받아 초기화한 후 반환해주는 함수
*
* @param V 	정점의 수
* @param E 	간선의 수
* @return graph*
*/
static graph* init_graph(int V, int E){
	graph* g = (graph*)malloc(sizeof(graph));
	g->V = V;
	g->E = E;
	g->edges = (edge*)malloc(sizeof(edge)*E);
	return g;
}

/**
* @brief 		그래프를 할당 해제해주는 함수
*
* @param g
*/
static void release_graph(graph* g){
	free(g->edges);
	free(g);
}


/**
* @brief 		Disjoint set을 초기화 후 반환해주는 함수
*
* @param V 	정점의 수
* @return disjoint_set*
*/
static disjoint_set* init_set(int V){
	int i;
	disjoint_set* set;
	set = (disjoint_set*)malloc(sizeof(disjoint_set));
	set->size = V;
	set->group = (int*)malloc(sizeof(int)*V);
	for (i = 0; i < V; i += 1){
		set->group[i] = i;
	}
	return set;
}

/**
* @brief 		Disjoint_set을 할당 해제해주는 함수
*
* @param set
*/
static void release_set(disjoint_set* set){
	free(set->group);
	free(set);
}

#endif