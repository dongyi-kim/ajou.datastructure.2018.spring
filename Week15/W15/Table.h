#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h" 

#define MAX_TBL     100

typedef int HashFunc(Key k);

typedef struct _table {
	Slot tbl[MAX_TBL];
	HashFunc * hf;
}Table;

// table initialization
void TBLInit(Table * pt, HashFunc * f);

// insertion
void TBLInsert(Table * pt, Key k, Value v);

// deletion
Value TBLDelete(Table * pt, Key k);

// search
Value TBLSearch(Table * pt, Key k);

#endif