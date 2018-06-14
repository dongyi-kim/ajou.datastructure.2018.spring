#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

/* Simple Hash Function �����ϴ� �ڵ� */
/* 
	Overflow, Collision handler�� �����ϴ�.
	Slot.h �� Table.c �ڵ忡�� hash chaining ����� ����ؼ� overflow, collision �� �ذ��մϴ�.
	
*/

int MyHashFunc(int k) {
	return k % 100;    // our hash function
}

int main(void) {
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;

	TBLInit(&myTbl, MyHashFunc);

	// data insert
	np = MakePersonData(20160003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	printf("item inserted\n");

	np = MakePersonData(20130012, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);
	printf("item inserted\n");

	np = MakePersonData(20170049, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);
	printf("item inserted\n");

	printf("\n");

	// data search
	printf("searching for 20160003\n");
	sp = TBLSearch(&myTbl, 20160003);
	if(sp != NULL)
		ShowPerInfo(sp);

	printf("searching for 20130012\n");
	sp = TBLSearch(&myTbl, 20130012);
	if(sp != NULL)
		ShowPerInfo(sp);

	printf("searching for 20170049\n");
	sp = TBLSearch(&myTbl, 20170049);
	if(sp != NULL)
		ShowPerInfo(sp);

	printf("\n");

	// data delete
	rp = TBLDelete(&myTbl, 20160003);
	if(rp != NULL) {
		free(rp);
		printf("item deleted\n");
	}

	rp = TBLDelete(&myTbl, 20130012);
	if (rp != NULL) {
		free(rp);
		printf("item deleted\n");
	}

	rp = TBLDelete(&myTbl, 20170049);
	if (rp != NULL) {
		free(rp);
		printf("item deleted\n");
	}

	getchar();

	return 0;
}