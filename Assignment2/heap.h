#pragma once
#pragma warning(disable: 4996)
#include<stdio.h>

#ifndef __HEAP_H__
#define __HEAP_H__

#include "graph.h"

/**
* @brief 		두 간선 a, b에 대한 비교 연산자 함수
*
* @param a 	좌항
* @param b 	우항
* @return int 	a가 오름차순으로 앞서면 음수, b가 앞서면 양수, 같으면 0
*/
static int compare(const edge *a, const edge *b) {
	if (a->weight == b->weight){
		// 가중치가 같은 간선은 인덱스에 대해 오름차순으로 비교한다 
		return a->index - b->index;
	}
	else{
		// 가중치가 다른 간선은 가중치에 대해 오름차순으로 비교한다
		return a->weight - b->weight;
	}
	return 0;
}

/**
* @brief 	두 포인터 a, b위치에 저장된 값을 교환하는 함수
*
* @param a
* @param b
*/
static void swap(edge *a, edge *b){
	edge temp = *a;
	*a = *b;
	*b = temp;
}

void heap_sort(edge* arr, int size);

#endif