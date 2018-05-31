#pragma warning(disable: 4996)
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<malloc.h>
#include<stdlib.h>


#define MAX_NODE_SIZE 1000      // 최대 정점의 수 

#define INFINITY	123456789   // 무한대 가중치 (정점간 경로가 없는 경우)
#define NONE		-1          // 빈 정점 인덱스 

typedef struct Graph Graph;     // 그래프 구조체 

/**
* @brief   인접 행렬로 그래프를 표현하는 구조체
*          정점은 0 ~ (V-1) 사이의 인덱스를 가진다
*/
typedef struct Graph{
	int V;      // 정점의 수
	int** W;    // 2차원 인접행렬 W[V][V]
};

/**
* @brief       그래프 초기화 후 반환
*
* @param V     정점의 수
* @return Graph*   그래프
*/
Graph* init_graph(const int V){
	int i, j;
	Graph* g = (Graph*)malloc(sizeof(Graph));
	g->V = V;
	g->W = (int**)malloc(sizeof(int*) * V);
	for (i = 0; i < V; i += 1){
		g->W[i] = (int*)malloc(sizeof(int*) * V);
		for (j = 0; j < V; j += 1){
			if (i == j){
				// 자기 자신으로 향하는 거리는 0 
				g->W[i][j] = 0;
			}
			else{
				// 초기에는 모든 간선이 없는 것으로 표시 
				g->W[i][j] = INFINITY;
			}
		}
	}
	return g;
}

/**
* @brief   그래프 할당을 해제해주는 함수
*
* @param g 그래프 포인터
*/
void release_graph(const Graph* g){
	int i, j;
	for (i = 0; i < g->V; i += 1){
		free(g->W[i]);
	}
	free(g->W);
	free(g);
}

/**
* @brief           해당 그래프의 최단거리 정보와 경로를 출력해주는 함수
*
* @param g         그래프 구조체
* @param origin    출발 노드
* @param D         D[v] := 출발 노드로부터 v번 노드까지의 최단 거리
* @param P         P[v] := 출발 노드로부터 v번 노드에 도달하기 위해 직전에 경유해야 할 정점의 번호 (최단 경로상 바로 이전 정점)
*/
void print_path_info(const Graph* g, const int origin, int *D, int *P){
	int i, j;
	int top = 0;
	int stack[MAX_NODE_SIZE];

	for (i = 0; i < g->V; i += 1){ // 모든 정점에 대해 
		// P배열을 사용해 i번 정점까지의 최단 경로를 스텍에 역순으로 저장한다 
		int cur;
		for (cur = i; cur != NONE; cur = P[cur]){
			stack[top++] = cur;
		}

		if (D[i] == INFINITY){
			// 도달할 수 없는 정점이라면 무시한다 
			printf(" - Path from '#%d' to '#%d' (length : INFINITY) NO PATH\n", origin, i);
		}
		else{
			// 해당 정점까지의 최단 경로 정보를 출력한다
			printf(" - Path from '#%d' to '#%d' (length : %d) ", origin, i, D[i]);
			printf("{ ");

			// 스택에 역순으로 저장된 경로 정보를 출력한다
			while (top > 0){
				printf("%d", stack[--top]);
				if (top > 0){
					printf(" => ");
				}
			}
			printf(" }\n");
		}
	}
}

/**
* @brief           그래프 g에 정점 source로 부터 정점 dest로 향하는 단방향 간선을 추가한다. weigh는 가중치다
*
* @param g         그래프 구조체
* @param source    출발 정점 번호
* @param dest      도착 정점 번호
* @param weight    간선의 가중치
*/
void add_edge(const Graph* g, const int source, const int dest, const int weight){
	g->W[source][dest] = weight;
}

/**
* @brief           그래프 g에 대해 벨만포드 알고리즘을 수행한 후 결과를 출력하는 함수
*
* @param g         그래프 구조체
* @param origin    출발 정점의 인덱스
*/
void BellmanFord(const Graph* g, const int origin){
	int i, j;   //
	int steps;  // 반복 횟수 

	// 해당 그래프가 Negative Cycle을 가진다면 true로 변경시켜 주어야 할 변수
	bool has_negative_cycle = false;

	// D[v] :=  정점 origin부터 정점 v로 향하는 최단 경로의 길이
	//          경로가 존재하지 않는다면 D[v] == INFINITY 
	int* D = (int*)malloc(sizeof(int) * g->V);

	// P[v] := 정점 origin에서 정점 v로 향하는 최단경로 상에서 v번 정점 바로 이전 정점 번호 
	//         P[origin] = NONE
	int* P = (int*)malloc(sizeof(int) * g->V);

	for (i = 0; i < g->V; i += 1){
		D[i] = INFINITY;
		P[i] = NONE;
	}

	D[origin] = 0;

	for (steps = 1; steps <= g->V; steps += 1){
	}

	if (has_negative_cycle){
		printf("This graph 'g' has negative cycle from origin node!!\n");
		return;
	}
	else {
		print_path_info(g, origin, D, P);
	}
}

Graph* test_case_1(){
	Graph* g = init_graph(6);
	printf("Test Case #1 ============================ \n");
	add_edge(g, 0, 1, 10);
	add_edge(g, 0, 2, 5);
	add_edge(g, 1, 2, 2);
	add_edge(g, 1, 3, 1);
	add_edge(g, 2, 1, 3);
	add_edge(g, 2, 3, 9);
	add_edge(g, 2, 4, 2);
	add_edge(g, 3, 4, 4);
	add_edge(g, 4, 0, 7);
	add_edge(g, 4, 3, 6);
	return g;
}

Graph* test_case_2(){
	Graph* g = init_graph(6);
	printf("Test Case #2 ============================ \n");
	add_edge(g, 0, 1, 1);
	add_edge(g, 1, 2, 1);
	add_edge(g, 2, 3, 1);
	add_edge(g, 3, 4, 1);
	add_edge(g, 4, 5, 1);
	add_edge(g, 5, 1, 1);

	add_edge(g, 1, 0, 1);
	add_edge(g, 2, 1, 1);
	add_edge(g, 3, 2, 1);
	add_edge(g, 4, 3, 1);
	add_edge(g, 5, 4, 1);
	add_edge(g, 1, 5, 1);
	return g;
}

Graph* test_case_3(){
	Graph* g = init_graph(6);
	printf("Test Case #3 ============================ \n");
	add_edge(g, 0, 1, 10);
	add_edge(g, 0, 2, 5);
	add_edge(g, 1, 2, 2);
	add_edge(g, 1, 3, 1);
	add_edge(g, 2, 1, 3);
	add_edge(g, 2, 3, 9);
	add_edge(g, 2, 4, 2);
	add_edge(g, 3, 4, 4);
	add_edge(g, 4, 0, 7);
	add_edge(g, 4, 3, 6);
	add_edge(g, 0, 3, 1);
	add_edge(g, 3, 4, -2);
	return g;
}

Graph* test_case_4(){
	Graph* g = init_graph(6);
	printf("Test Case #4 ============================ \n");
	add_edge(g, 0, 1, -1);
	add_edge(g, 1, 2, 1);
	add_edge(g, 2, 3, 1);
	add_edge(g, 3, 4, 1);
	add_edge(g, 4, 5, -1);
	add_edge(g, 5, 1, -1);

	add_edge(g, 1, 0, -1);
	add_edge(g, 2, 1, 1);
	add_edge(g, 3, 2, 1);
	add_edge(g, 4, 3, 1);
	add_edge(g, 5, 4, 1);
	add_edge(g, 1, 5, -1);
	return g;
}

int main(){
	printf("학번 : 201223456, 이름 : 홍길동\n\n");

	// 아래 네 테스트케이스 함수를 차례로 수행하여 결과를 캡처해주세요
	//  - test_case_1(), test_case_2(), test_case_3(), test_case_(4)
	Graph* g = test_case_3();
	BellmanFord(g, 0);

	getchar();
	return 0;
}