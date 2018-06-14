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
    // 노드 u가 기존에 가리키던 대표 노드의 번호를 가져온다
	int u_boss = set->group[u];

	// 현재 자기 자신이 해당 그룹의 대표 노드라면 자기 자신을 반환한다
	if (u_boss == u){
		return u;
	}

    // 기존에 가리키던 대표 노드의 정보를 갱신한다
	u_boss = find_set(set, u_boss);

	// 갱신된 대표 노드 정보를 자신에게도 캐싱한다
	set->group[u] = u_boss;

	// 찾은 대표 노드 번호를 반환한다
	return u_boss;
}


/**
* @brief       Disjoint Set의 두 노드 u, v가 속한 두 그룹을 병합하는 연산
*
* @param set   disjoint set 포인터
* @param u     노드 번호 1
* @param v     노드 번호 2
*/
void union_set(disjoint_set* set, int u, int v){
	int u_boss, v_boss;

	// 노드 u가 속한 그룹의 대표 번호를 찾는다
	u_boss = find_set(set, u);

	// 노드 v가 속한 그룹의 대표 번호를 찾는다
	v_boss = find_set(set, v);

	// 노드 u가 속한 그룹을 노드 v가 속한 그룹에 귀속시킨다
	set->group[u_boss] = v_boss;
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

	// 그래프 g의 모든 간선을 가중치에 대해 오름차순으로 정렬한다
	heap_sort(g->edges, g->E);

    // 간선을 하나씩 추가하며 Spanning Tree를 만들어 나간다
	for (i = 0, j = 0; i < g->E; i += 1){
		int u = g->edges[i].origin;
		int v = g->edges[i].dest;

        // 이미 연결 된 두 노드를 가리키는 간선이라면 건너뛴다
        // 사이클이 생기기 때문
		if (find_set(set, u) == find_set(set, v)){
			continue;
		}

		// 해당 간선을 추가한다
		spanning_tree->edges[j++] = g->edges[i];

		// 해당 두 노드의 연결 정보를 반영해준다
		union_set(set, u, v);
	}
	
	release_set(set);	
	return spanning_tree;
}
