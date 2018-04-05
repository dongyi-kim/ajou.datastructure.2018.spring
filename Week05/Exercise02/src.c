#include <stdio.h>
#include <malloc.h>

typedef char element;     // define element as character
typedef struct QNode {    // define linked queue node using structure
	element data;
	struct QNode *link;
} QNode;

typedef struct {		// define pointer front and rear
	QNode *front, *rear;
} LQueueType;

// create linked queue
LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// is empty
int isEmpty(LQueueType *LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// add item to the rear of the queue
void enQueue(LQueueType *LQ, element item) {

}

// dequeue
element deQueue(LQueueType *LQ) {


}

// print all items in the queue
void printLQ(LQueueType *LQ) {
	QNode *temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}

void main(void) {
	LQueueType *LQ = createLinkedQueue();  // create a linked queue
	element data;
    
	printf("\n ***** Queue ***** \n");
	printf("\n enqueue A >>");  enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n enqueue B >>");  enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n enqueue C >>");  enQueue(LQ, 'C'); printLQ(LQ);
	printf("\n dequeue   >>");  data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeued data: %c", data);
	printf("\n dequeue   >>");  data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeued data: %c", data);
	printf("\n dequeue   >>");  data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeued data: %c", data);
	getchar();
}

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char element;     // define element as character
typedef struct QNode {    // define linked queue node using structure
	element data;
	struct QNode *link;
} QNode;

typedef struct {		// define pointer front and rear
	QNode *front, *rear;
} LQueueType;

// create linked queue
LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// is empty
int isEmpty(LQueueType *LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// add item to the rear of the queue
void enQueue(LQueueType *LQ, element item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// if the current queue is empty
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {						// if not empty
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

// dequeue
element deQueue(LQueueType *LQ) {
	QNode *old = LQ->front;
	element item;
	if (isEmpty(LQ)) return 0; // if empty
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

// print all items in the queue
void printLQ(LQueueType *LQ) {
	QNode *temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}

void main(void) {
	LQueueType *LQ = createLinkedQueue();  // create a linked queue
	element data;

	printf("\n ***** Queue ***** \n");
	printf("\n enqueue A >>");  enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n enqueue B >>");  enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n enqueue C >>");  enQueue(LQ, 'C'); printLQ(LQ);
	printf("\n dequeue   >>");  data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeued data: %c", data);
	printf("\n dequeue   >>");  data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeued data: %c", data);
	printf("\n dequeue   >>");  data = deQueue(LQ); printLQ(LQ);
	printf("\tdequeued data: %c", data);
	getchar();
}
