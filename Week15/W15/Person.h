#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN    50

typedef struct _person {
	int ssn;    // social security number 
	char name[STR_LEN];    // name
	char addr[STR_LEN];    // address
} Person;

int GetSSN(Person * p);

void ShowPerInfo(Person * p);

Person *MakePersonData(int ssn, char * name, char * addr);

#endif