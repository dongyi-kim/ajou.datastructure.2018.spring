#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdbool.h>
#include<memory.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct disjoint_set{
	int size;		// number of nodes in the set
	int* parents;	// parents[i] := the boss's index of the group that node #i belongs to.
} disjoint_set;


/**
 * @brief 	새로운 집합 정보를 생성한 후 초기화하여 반환하는 함수
 * 
 * @param number_of_nodes 	관리할 노드의 수 
 * @return disjoint_set* 	새로 생성된 집합의 포인터
 */
disjoint_set* init_disjoint_set(int number_of_nodes){
	int node_index;
	disjoint_set* new_set = (disjoint_set*)malloc(sizeof(disjoint_set));
	new_set->size = number_of_nodes;
	new_set->parents = (int*)malloc(sizeof(int)*number_of_nodes);

	// 처음에는 자기 자신을 boss로 가진다.
	for (node_index = 0; node_index < number_of_nodes; node_index += 1){
		new_set->parents[node_index] = node_index;
	}
	return new_set;
}

/**
 * @brief 할당 해제 해 주는 함수
 * 
 * @param set_ptr 
 */
void release_dijoint_set(disjoint_set* set_ptr){
	free(set_ptr->parents);
	free(set_ptr);
}

/**
 * @brief 노드 u에 대해, 현재 자신이 속한 그룹의 대표 노드(boss)의 인덱스를 반환하는 함수
 * 
 * @param set_ptr 
 * @param u 
 * @return int 
 */
int find_parent(disjoint_set* set_ptr, int u){
	int u_boss = 


	//printf("The boss of a group that the node #%d belongs to is node #%d\n", u, u_boss);
	return u_boss;
}

/**
 * @brief 노드 u와 v가 속한 두 그룹을 병합하는 함수 
 * 
 * @param set_ptr 
 * @param u 
 * @param v 
 */
void union_set(disjoint_set* set_ptr, int u, int v){


	//printf("Merged two groups of node #%d and node #%d.\n", u, v);
}

/**
 * @brief 두 노드 u와 v가 같은 그룹에 속해 있다면 true, 그렇지 않다면 false를 반환하는 함수
 * 
 * @param set_ptr 
 * @param u 
 * @param v 
 * @return true 
 * @return false 
 */
bool is_same_group(disjoint_set* set_ptr, int u, int v){
	int u_boss = find_parent(set_ptr, u);
	int v_boss = find_parent(set_ptr, v);
	bool yes = (u_boss == v_boss);
	
	if (yes){
		printf("Node #%d and Node #%d are in the same group with the boss #%d.\n", u, v, u_boss);
	}
	else{
		printf("Node #%d and Node #%d are not in the same group.\n", u, v, u_boss);
	}
	return yes;
}

/**
 * @brief 현재 disjoint set의 집합 현황을 출력해주는 함수
 * 
 * @param set_ptr 
 */
void print_sets(disjoint_set* set_ptr){
	int boss = 0;
	int member = 0;
	printf("[Set Information]\n");
	for (boss = 0; boss < set_ptr->size; boss += 1){
		if (set_ptr->parents[boss] == boss){
			printf(" (Boss: %d) {", boss);
			for (member = 0; member < set_ptr->size; member += 1){
				int my_boss = find_parent(set_ptr, member);
				if (my_boss == boss){
					printf("  %d  ", member);
				}
			}
			printf(" }\n");
		}
	}
	printf("\n");
}

void test_case_1(){
	disjoint_set* set_ptr = init_disjoint_set(7);

	union_set(set_ptr, 0, 2);
	is_same_group(set_ptr, 0, 6);
	union_set(set_ptr, 6, 5);
	is_same_group(set_ptr, 6, 0);
	union_set(set_ptr, 2, 6);
	union_set(set_ptr, 3, 1);
	union_set(set_ptr, 0, 0);
	is_same_group(set_ptr, 0, 0);

	print_sets(set_ptr);
	release_dijoint_set(set_ptr);
}

void test_case_2(){
	disjoint_set* set_ptr = init_disjoint_set(31);
	
	union_set(set_ptr, 11, 18);
	union_set(set_ptr, 3, 5);
	is_same_group(set_ptr, 1, 1);
	is_same_group(set_ptr, 12, 30);
	union_set(set_ptr, 3, 3);
	union_set(set_ptr, 4, 13);
	union_set(set_ptr, 23, 17);
	is_same_group(set_ptr, 7, 23);
	is_same_group(set_ptr, 13, 6);
	union_set(set_ptr, 27, 18);
	is_same_group(set_ptr, 8, 7);
	is_same_group(set_ptr, 13, 2);
	is_same_group(set_ptr, 0, 4);
	union_set(set_ptr, 15, 5);
	union_set(set_ptr, 17, 14);
	union_set(set_ptr, 30, 17);
	is_same_group(set_ptr, 29, 7);
	union_set(set_ptr, 3, 13);
	union_set(set_ptr, 18, 7);
	is_same_group(set_ptr, 1, 13);
	is_same_group(set_ptr, 19, 28);
	union_set(set_ptr, 24, 8);
	is_same_group(set_ptr, 4, 30);
	union_set(set_ptr, 18, 25);
	is_same_group(set_ptr, 9, 18);
	is_same_group(set_ptr, 5, 18);
	union_set(set_ptr, 2, 23);
	is_same_group(set_ptr, 6, 8);
	is_same_group(set_ptr, 1, 20);
	union_set(set_ptr, 15, 29);

	print_sets(set_ptr);

	union_set(set_ptr, 30, 7);
	is_same_group(set_ptr, 17, 7);
	is_same_group(set_ptr, 18, 6);
	union_set(set_ptr, 19, 12);
	is_same_group(set_ptr, 14, 3);
	union_set(set_ptr, 2, 14);
	union_set(set_ptr, 25, 8);
	is_same_group(set_ptr, 28, 8);
	union_set(set_ptr, 12, 11);
	is_same_group(set_ptr, 6, 26);
	union_set(set_ptr, 11, 1);
	is_same_group(set_ptr, 4, 22);
	union_set(set_ptr, 28, 20);
	is_same_group(set_ptr, 5, 24);
	is_same_group(set_ptr, 13, 23);
	union_set(set_ptr, 19, 0);
	union_set(set_ptr, 11, 9);
	is_same_group(set_ptr, 13, 28);
	union_set(set_ptr, 17, 15);
	union_set(set_ptr, 20, 0);
	union_set(set_ptr, 0, 2);
	is_same_group(set_ptr, 0, 6);
	union_set(set_ptr, 6, 5);
	is_same_group(set_ptr, 6, 0);
	union_set(set_ptr, 2, 6);
	union_set(set_ptr, 3, 1);
	union_set(set_ptr, 0, 0);
	is_same_group(set_ptr, 0, 0);

	print_sets(set_ptr);
	release_dijoint_set(set_ptr);
}

int main(){
	// 본인 학번과 이름을 출력하세요 
	printf("[Student ID] 201724516\n");
	printf("[NAME] HONG KIL-DONG\n");

	test_case_1();		// 테스트용
	//test_case_2();	// 제출용 테스트 케이스 

	return 0;
}