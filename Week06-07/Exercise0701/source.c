#pragma disable(warning: 4996)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode {	// define treeNode
	char data;
	struct treeNode *left;  // left subTree link
	struct treeNode *right; // right subTree link
} treeNode;

/**
 * @brief 
 * 		Create a new tree node having value 'data' and two child sub-tree 'leftNode' and 'rightNode'
 * 		Null means empty child sub-tree.
 * 
 * @param data 			the data that new node will store
 * @param leftNode 		the pointer of left child node of new node
 * @param rightNode 	the pointer of right child node of new node
 * @return treeNode* 	return the pointer new node
 */
treeNode* makeNode(char data, treeNode* leftNode, treeNode* rightNode) {

}

/**
 * @brief 
 * 		print all values of nodes in the sub tree of 'root' in pre-order.
 * 
 * @param root 	current root of the sub tree.
 */
void preorder(treeNode* root) {

}

/**
 * @brief 
 * 		print all values of nodes in the sub tree of 'root' in inorder-order.
 * 
 * @param root 	current root of the sub tree.
 */
void inorder(treeNode* root) {

}

/**
 * @brief 
 * 		print all values of nodes in the sub tree of 'root' in post-order.
 * 
 * @param root 	current root of the sub tree.
 */
void postorder(treeNode* root) {

}

/**
* @brief
* 		release(free) all pointers of each nodes in sub-tree of the root.
*
* @param root 	current root of the sub tree.
*/
void release(treeNode* root) {

}

int main() {
	// making a binary tree that reflects (A*B-C/D) 
	treeNode* n7 = makeNode('D', NULL, NULL);
	treeNode* n6 = makeNode('C', NULL, NULL);
	treeNode* n5 = makeNode('B', NULL, NULL);
	treeNode* n4 = makeNode('A', NULL, NULL);
	treeNode* n3 = makeNode('/', n6, n7);
	treeNode* n2 = makeNode('*', n4, n5);
	treeNode* n1 = makeNode('-', n2, n3);

	printf("Preorder : ");
	preorder(n1);
	printf("\n");
		

	printf("inorder : ");
	inorder(n1);
	printf("\n");

	printf("postorder : ");
	postorder(n1);
	printf("\n");

	release(n1);
	getchar();
	return 0;
}