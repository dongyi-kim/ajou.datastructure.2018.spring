#pragma warning(disable: 4996)
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX_SIZE 100
int buffer[MAX_SIZE];				// buffer

/**
 * @brief  a[leftEnd] ~ a[rightEnd]를 병합정렬해주는 함수
 * 
 * @param a 
 * @param leftEnd 
 * @param rightEnd 
 */
void mergeSort(int a[], int leftEnd, int rightEnd) {
	int middleEnd;
	if (leftEnd >= rightEnd){
		return;
	}

	middleEnd = (leftEnd + rightEnd) / 2;

	// fill your code here
}

int main() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	int i;
	mergeSort(list, 0, size - 1);

	for (i = 0; i < size; i += 1){
		if (i > 0){
			printf(", ");
		}
		printf("%d", list[i]);
	}

	return 0;
}
