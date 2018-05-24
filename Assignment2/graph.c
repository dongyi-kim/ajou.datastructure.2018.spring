#pragma warning(disable: 4996)
#include<stdio.h>

#include "graph.h"
#include "heap.h"

/* [참고자료]
*  - 강의노트
*  - https://ko.wikipedia.org/wiki/%ED%81%AC%EB%9F%AC%EC%8A%A4%EC%BB%AC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
*  - https://www.youtube.com/watch?v=AMByrd53PHM
*  - https://www.youtube.com/watch?v=LQ3JHknGy8c
*/

/**
* @brief       노드 u가 속한 그룹의 번호를 반환하는 연산
*
* @param set   disjoint set의 포인터
* @param u     대상 노드 번호
* @return int  해당 그룹이 속한 그룹 번호(그룹 대표 노드의 번호)
*/
int find_set(disjoint_set* set, int u){

}


/**
* @brief       Disjoint Set의 두 노드 u, v가 속한 두 그룹을 병합하는 연산
*
* @param set   disjoint set 포인터
* @param u     노드 번호 1
* @param v     노드 번호 2
*/
void union_set(disjoint_set* set, int u, int v){

}


/**
* @brief 	그래프 g의 최소 스패닝 트리 그래프를 찾아 반환하는 함수
*
* @param g 			대상 그래프
* @return graph_t* 	스패닝 트리 그래프의 포인터
*/
graph* find_minimum_spanning_tree(graph* g){
	int i;
	int j;
	disjoint_set* set;
	graph* spanning_tree;

	set = init_set(g->V);
	spanning_tree = init_graph(g->V, g->V - 1);



	release_set(set);
	return spanning_tree;
}
