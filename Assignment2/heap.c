#pragma warning(disable: 4996)
#include<stdio.h>

#include "heap.h"

#define LEFT_CHILD(P)	( (P) * 2 + 1 )
#define RIGHT_CHILD(P)	( (P) * 2 + 2 )

/* [참고자료]
*  - 강의노트
*  - https://ratsgo.github.io/data%20structure&algorithm/2017/09/27/heapsort/
*  - https://youtu.be/ehNVf2Bcm2Q
*/


/**
* @brief		한 노드(root)의 좌/우 서브트리가 각각 heap일 때,
*				두 서브트리와 루트를 병합한 후 heap성질을 만족시키는 함수
*
* @notice 		배열의 인덱스는 tree[0] ~ tree[size-1]임에 유의할 것.
*				원소간의 비교에는 compare함수를 사용한다
*
* @param tree  트리 배열의 포인터
* @param root  heapify를 적용 할 서브 트리의 루트 노드 번호
* @param size  트리 배열의 전체 크기
*/
void heapify(edge* tree, int root, int size){
	int parent = root;
	while (parent < size){

	}
}

/**
* @brief       배열 전체에 Heapify를 적용하여 Max-Heap으로 만드는 함수
*
* @notice      배열의 인덱스는 tree[0] ~ tree[size-1]임에 유의할 것.
*
* @param tree
* @param size
*/
void build_heap(edge* tree, int size){
	int parent;
	for (parent = size / 2; parent >= 0; parent -= 1){

	}
}

/**
* @brief      	원소들을 compare함수 기준으로 오름차순 힙정렬해주는 함수
*
* @notice      	반드시 "heap.h", "heap.c"에 정의된 함수들을 사용하여 정렬한다
*
* @param edges 정렬 할 간선 배열
* @param size  간선의 수
*/
void heap_sort(edge* arr, int size){

}

