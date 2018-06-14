#pragma warning(disable: 4996)

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


/**
 * @brief 배열 전체를 삽입 정렬로 정렬하는 함수 
 * 
 * @param a 
 * @param size 
 */
void insertionSort(int a[], int size) {
	int i, j, t, temp;
	
	// fill your code here
}


int main() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	int i;

	insertionSort(list, size);

	for (i = 0; i < size; i += 1){
		if (i > 0){
			printf(", ");
		}
		printf("%d", list[i]);
	}

	getchar();
	return 0;
}

