#pragma disable(warning: 4996)
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100
#define MALLOC(p,s) (p) = (nodePointer) malloc((s));

// structure
typedef struct node *nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};

int main() {
	bool out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	nodePointer x, y, top;
	int i, j, n;

	// receiving the number of polygons
	printf("Enter the number of polygons (<= %d) ", MAX_SIZE);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		out[i] = true;
		seq[i] = NULL;
	}

	/* Phase 1: Input the equivalence pairs */
	// getting pairs (two polygons for each pair)
	printf("Enter a pair of numbers (-1 -1 to quit): ");
	
	while(1){
		scanf("%d%d", &i, &j);

		if (i < 0 || j < 0){
			break;
		}

		MALLOC(x, sizeof(x));
		x->data = j; x->link = seq[i]; seq[i] = x;

		MALLOC(x, sizeof(x));
		x->data = i; x->link = seq[j]; seq[j] = x;

		printf("Enter a pair of numbers (-1 -1 to quit): ");
	};

	/* Phase 2: output the equivalence classes */
	for (i = 0; i < n; i++) {
		
	}

	getchar();
	return 0;
}