#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person * p) {
	return p->ssn;
}

void ShowPerInfo(Person * p) {
	printf("Social Security Number: %d \n", p->ssn);
	printf("Name: %s \n", p->name);
	printf("Addr: %s \n\n", p->addr);
}

Person * MakePersonData(int ssn, char * name, char * addr) {
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy_s(newP->name, 50, name);
	strcpy_s(newP->addr, 50, addr);
	return newP;
}
