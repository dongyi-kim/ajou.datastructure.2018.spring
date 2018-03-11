#pragma warning(disable: 4996)
#include<stdio.h>


long long fact(int);


int main()
{
	int n;
	long long result;
	printf("학번 201821234 이름 홍길동\n\n");

	//n을 입력받는다
	printf("Input 'N'\n> ");
	scanf("%d", &n);

	//fact(n)을 호출해 수열의 n번째 값을 전달받는다.
	result = fact(n);

	//결과를 출력한다.
	printf("%lld\n", result);

	getchar();
	return 0;
}

/**
 * @brief 
 * 항의 번호 n을 입력받아서 펙토리얼 수열의 n번째 항을 반환해주는 함수
 * 재귀적으로 구현해야 한다
 * 가장 먼저 호출된 항의 번
 * 
 * @param n  계산하고자 하는 펙토리얼 수열 항의 번호 
 * @return long long 펙토리열 수열의 n번째 항 
 */
long long fact(int n) 
{
	long long value;

	if (n <= 1)
	{
		printf("fact(1) called!\n");
		printf("fact(1) returned!!\n");

		/**
		 * @brief 
		 * n이 1이하 일 때에는 어떻게 처리해야 할 까?
		 */
		// return someting....
	}
	else {
		printf("fact(%d) called!! \n", n);

		/**
		 * @brief 
		 * 재귀적으로 n번째 항을 계산하려면 어떻게 해야할 까?
		 */
		// value = someting ....

		printf("fact(%d) returned value: %lld !!\n", n, value);
		return value;
	}
}