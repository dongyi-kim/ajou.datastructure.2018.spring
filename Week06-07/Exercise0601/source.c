#pragma disable(warning: 4996)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// doubled linked list
typedef struct ListNode {
	struct ListNode* llink;	// left link
	char data[4];			// data of a node. arbitrary 3-character string.
	struct ListNode* rlink; // right link
} listNode;

// define a node that indicates a head of the linked list
typedef struct {
	listNode* head;
} linkedList_h;

// create empty linked list
linkedList_h* createLinkedList_h(void) {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));	// assign a space to the head node
	DL->head = NULL;									// put null as the linked list is empty
	return DL;
}

// print all data in the linked list
void printList(linkedList_h* DL) {
	listNode* p;
	printf(" DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

/**
 * @brief 
 * 		Create new node having value 'x' and insert into the list 
 * 
 * @param DL 	the pointer of header node of list.
 * @param pre 	the pointer of previous(left) node of new node.
 * @param x 	the value that new node will store.
 */
void insertNode(linkedList_h* DL, listNode *pre, char*x) {

}

/**
 * @brief 
 * 		remove a node from list 
 * 
 * @param DL 	the pointer of header node of list.
 * @param old 	the pointer of the node to remove
 */
void deleteNode(linkedList_h* DL, listNode* old) {

}

/**
 * @brief 
 * 		Find a node having same value with 'x' and return pointer of that node.
 * 
 * @param DL 	the pointer of header node of list.
 * @param x 	value to search
 * @return listNode* 	pointer of a node that have same value with 'x'. if doesn't exist, return null.
 */
listNode* searchNode(linkedList_h* DL, char* x) {

}

int main() {
	linkedList_h* DL;
	listNode *p;
	DL = createLinkedList_h();  // create an empty node
	printf("(1) create a doubly linked list. \n");
	printList(DL); 
	getchar();

	printf("(2) Insert A. \n");
	insertNode(DL, NULL, "A");
	printList(DL); 
	getchar();

	printf("(3) Insert B after A. \n");
	p = searchNode(DL, "A"); 
	insertNode(DL, p, "B");
	printList(DL); 
	getchar();

	printf("(4) Insert C after B. \n");
	p = searchNode(DL, "B"); 
	insertNode(DL, p, "C");
	printList(DL); 
	getchar();

	printf("(5) Delete B. \n");
	p = searchNode(DL, "B");      	
	deleteNode(DL, p);
	printList(DL); 
	getchar();

	return 0;
}