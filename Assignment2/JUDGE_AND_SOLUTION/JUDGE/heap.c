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
				원소간의 비교에는 compare함수를 사용한다
*
* @param tree  트리 배열의 포인터
* @param root  heapify를 적용 할 서브 트리의 루트 노드 번호
* @param size  트리 배열의 전체 크기
*/
void heapify(edge* tree, int root, int size){
	int parent = root;
	while (parent < size){
	    // 왼쪽 자식노드의 인덱스
		int lchild = LEFT_CHILD(parent);

		// 오른쪽 자식 노드의 인덱스
		int rchild = RIGHT_CHILD(parent);

		// 부모와 두 자식 노드들 중 가장 큰 값을 가지는 노드의 인덱스
		int largest = parent;

		// 왼쪽 노드가 존재하고, 가장 큰 값을 가진다면 해당 인덱스 저장
		if (lchild < size && compare(tree + largest, tree + lchild) < 0){
			largest = lchild;
		}

		// 오른쪽 노드가 존재하고, 가장 큰 값을 가진다면 해당 인덱스 저장
		if (rchild < size && compare(tree + largest, tree + rchild) < 0){
			largest = rchild;
		}

		if (largest == parent){
            // 만약 부모가 가장 큰 값을 가지는 노드라면, 이미 heap의 성질을 만족하므로 종료
			break;
		}
		else{
		   // 그렇지 않다면 가장 큰 값을 가진 자식과 부모 노드의 값을 교환한다.
			swap(tree + largest, tree + parent);
			parent = largest;
		}
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
	    // 리프노드들 부터 차례로 heap성질을 만족시켜나간다
		heapify(tree, parent, size);
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
    // 루트 노드는 0번 인덱스를 가진다
	int root = 0;

	// 배열 전체를 heap으로 만든다
	build_heap(arr, size);


	while (size > 1){
		int leaf = --size;

		// 현재 루트 노드는 최대값을 가지고 있다.
		// 이를 마지막 leaf에 강제로 배치 시킨다
		swap(arr + leaf, arr + 0);

		// 마지막 leaf를 제외한 트리에 대해 heap성질을 만족시킨다
		heapify(arr, 0, size);
	}
}
