#pragma warning(disable: 4996)
#include<stdio.h>


/*
int main(void)
{
	char ch = 'c';
	char *chptr = &ch;

	int i = 20;
	int *intptr = &i;

	char *ptr = "I am a string";

	//무엇이 출력될 지 예측해보세요
	printf("\n [%c], [%d], [%c], [%p], [%p], [%c], [%s]\n", *chptr, *intptr, *ptr, ptr, ptr+5, *(ptr+5), ptr);

	getchar();

	return 0;
}
*/


struct st {
	int a;
	char ch;
};

int main()
{
	printf("학번 201821234 이름 홍길동\n\n");

	struct st obj;
	struct st *stobj = &obj;

	//stobj 변수를 사용해서
	//obj.a 를 5로 변경해보세요 
	//obj.ch를 'a'로 변경해보세요

	printf("\n [%d] [%c]\n", stobj->a, stobj->ch);
	
	getchar();

	return 0;
}