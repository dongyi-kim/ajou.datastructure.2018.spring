#pragma warning(disable: 4996)

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/**
 * @brief a[begin] ~ a[end]를 퀵정렬로 정렬해주는 함수
 * 
 * @param a 
 * @param begin 
 * @param end 
 */
void quickSort(int a[], int begin, int end) {
	int p;


}

int main() {
	int list[8] = { 69, 10, 30, 2, 16, 8, 31, 22 };
	int size = 8;
	int i;
	quickSort(list, 0, size - 1);

	for (i = 0; i < size; i += 1){
		if (i > 0){
			printf(", ");
		}
		printf("%d", list[i]);
	}
	return 0;
}