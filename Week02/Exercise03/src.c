#pragma warning(disable: 4996)
#include <stdio.h>


/**
* @brief
* 'start' 기둥에 놓여있는 n개의 원반을 하노이 타워의 규칙을 만족하면서
* 'target' 기둥으로 모두 옮기는 함수
* # 'start'번 기둥에는 1번~n번 원반이 차례로 놓여있다.
* # 한 함수 안에서는 하나의 원반만을 옮기고, 나머지 기둥들은 재귀적으로 처리하시오 
* # 이번 함수에서 옮긴 원반 정보는 printf로 출력한다.
* 
* @param n		현재 'start'기둥에 있는 원반의 수
* @param start  현재 n개의 원반들이 놓여 있는 기둥
* @param work	세 기둥 중 출발점과 목적지가 아닌 남은 기둥
* @param target 원반들을 옮겨야 할 목적지 기둥 
*/
void hanoi(int n, char start, char work, char target)
{
	/**
	 * @brief 옮겨야 할 원반이 하나 뿐이라면?
	 */
	if (n == 1)
	{
		// printf("move object #%d from %c to %c\n", something...);
	}
	/**
	 * @brief 두 개 이상의 원반을 옮겨야 한다면?
	 */
	else
	{
		// move some objects...
		// printf("move object #%d from %c to %c\n", something...);
		// move some objects...
	}
}

int main()
{
	int n;
	printf("학번 201821234 이름 홍길동\n\n");
	printf("Number of disk. > ");
	scanf("%d", &n);

	//n개의 원반을 'A'기둥 에서 'C'기둥 으로 모두 옮긴다.
	hanoi(n, 'A', 'B', 'C');

	getchar();
	return 0;
}