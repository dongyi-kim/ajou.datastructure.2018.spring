#pragma warning(disable: 4996)
#include<stdio.h>
#include<time.h>

#define MAX_LENGTH (int)(61)

/**
 * @brief 피보나치 수열의 n번째 항을 재귀적으로 계산하는 함수
 * 
 * @param n 항 번호 
 * @return unsigned long long 피보나치 수열의 n번째 항의 값 
 */
unsigned long long recursive_fibo(unsigned int n)
{

}

/**
 * @brief 
 * 
 * @param n 항 번호 
 * @return unsigned long long 피보나치 수열의 n번째 항을 
 */
unsigned long long iterative_fibo(unsigned int n)
{

}

int main()
{
	unsigned int length;
	double begin, end;
	double t1, t2;
	unsigned long long val;
	printf("학번 201821234 이름 홍길동\n\n");

	/**
	 * @brief
	 * [1, MAX_LENGTH]의 범위에 대한 각 n에 대하여  
	 * n번째 항을 계산하는데 소요되는 시간을 각각 구하여 출력한다
	 */
	for (length = 1; length <= MAX_LENGTH; length += 5)
	{
		//resulsive method 
		begin = clock();
		val = recursive_fibo(length);
		end = clock();
		t1 = (end - begin) / CLOCKS_PER_SEC;

		//iterative method
		begin = clock();
		val = iterative_fibo(length);
		end = clock();
		t2 = (end - begin) / CLOCKS_PER_SEC;

		//print result
		printf("[Length: %3d] Reculsive : %.3lf sec , Iterative : %.3lf sec\n", length, t1, t2);
	}

	getchar();
	return 0;
}
