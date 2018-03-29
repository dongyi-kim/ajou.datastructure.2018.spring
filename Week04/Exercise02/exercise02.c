#pragma disable(warning: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE      	100
#define MAZE_SIZE				 6

typedef struct StackObjectRec {
	short r;
	short c;
} StackObject;

StackObject stack[MAX_STACK_SIZE];	// Stack
int top = -1;						// the index of top element in stack. 
									//'-1' means that no elements are in stack.

//stack initialization
void initialize() {
	top = -1;
}

bool isEmpty() {	//return true if the stack is empty (no elements)
	return (top == -1);
}

bool isFull() {  //return true if the stack is full of elements
	return (top == (MAX_STACK_SIZE - 1));
}


void push(StackObject item) {
	if (isFull()) {
		printf("stack is full\n");
		exit(-1);
	}
	else
		stack[++top] = item;
}

StackObject pop() {
	if (isEmpty()) {
		printf("stack is empty\n");
		exit(-1);
	}
	else
		return stack[top--];
}

/**
 * @brief 
 * 		Print all elements of stacks in console.
 */
void printStack() {
	int i;
	for (i = 5; i>top; i--)
		printf("|     |\n");
	for (i = top; i >= 0; i--)
		printf("|(%01d,%01d)|\n", stack[i].r, stack[i].c);
	printf("-------\n\n");
	printf("======================\n");
}

StackObject here = { 0, 0 };		// Current Position
StackObject entry = { 0, 0 };		// Initial Position (Entry)

/**
 * @brief 
 * 		Initial state of maze
 * 			e - means entry
 * 			x - means goal
 * 			0 - means passable way
 * 			1 - means non-passable way
 */
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ 'e', '0', '1', '1', '1', '1' },
	{ '1', '0', '1', '0', '0', '0' },
	{ '1', '0', '0', '0', '1', '0' },
	{ '1', '0', '1', '1', '0', '0' },
	{ '1', '0', '1', '0', '0', '1' },
	{ '1', '1', '1', '0', '0', 'x' },
};

/**
 * @brief 
 * 		print a map array of maze in console.
 * 			m - means current position of your algorithm.
 * 			. - means boards that already visited by your algorithm
 * 			else - same with definition of 'maze' array.
 * 
 * @param m 	array to print out
 */
void printMaze(char m[MAZE_SIZE][MAZE_SIZE]) {
	int r, c;
	printf("\n");
	for (r = 0; r<MAZE_SIZE; r++) {
		for (c = 0; c<MAZE_SIZE; c++) {
			if (c == here.c && r == here.r)
				printf("m ");
			else {
				if (m[r][c] == 0) printf("0 ");
				else printf("%c ", m[r][c]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

/**
 * @brief 
 * 			push visit information of location (r, c) into stack.
 *			BUT, DO NOTHING WHEN YOU SHOULD NOT VISIT LOCATION (r, c).
 * 
 * @param r 	visiting row index
 * @param c 	visiting column index
 */
void pushLoc(int r, int c);

/**
 * @brief 
 * 			find path from entry to goal using the search algorithm based on 'stack'			
 * 
 * @return true 	when some path exist. (your path should be marked as '.' ) 
 * @return false 	when no path exist at all
 */
bool search_maze();

int main() {
	bool result;
	printf("학번 201821234 이름 홍길동\n\n");

	//print initial state
	here = entry;
	printf("======================\n");
	printf("시작\n");
	printf("======================\n");
	printMaze(maze);
	printStack();

	//search maze
	result = search_maze();

	//print last state
	printf("======================\n");
	if (result == true)
	{
		printf("성공!!\n");
	}
	else{
		printf("실패!!\n");
	}
	printf("======================\n");
	printMaze(maze);
	printStack();

	getchar();
	return 0;
}

/**
* @brief
* 			push visit information of location (r, c) into stack.
*			BUT, DO NOTHING WHEN YOU SHOULD NOT VISIT LOCATION (r, c).
*
* @param r 	visiting row index
* @param c 	visiting column index
*/
void pushLoc(int r, int c) {








}


/**
* @brief
* 			find path from entry to goal using the search algorithm based on 'stack'
*
* @return true 	when some path exist. (your path should be marked as '.' )
* @return false 	when no path exist at all
*/
bool search_maze()
{
	while (maze[here.r][here.c] != 'x') {








	return true;
}
