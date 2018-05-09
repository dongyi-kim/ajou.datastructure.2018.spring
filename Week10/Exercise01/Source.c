#pragma warning(disable: 4996)

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<memory.h>
#include<malloc.h>

typedef char element;

struct node;
struct tree;
typedef struct node* node_ptr;
typedef struct tree* tree_ptr;

typedef struct node {
	element key;		// data field
	node_ptr left;		// pointer of the left child node
	node_ptr right;		// pointer of the right child node 
	node_ptr parent;	// pointer of the parent node
} node;

typedef struct tree{
	node_ptr root;		// pointer of the root node of tree.
};

tree_ptr make_tree(){
	tree_ptr new_tree = (tree_ptr)malloc(sizeof(struct tree));
	new_tree->root = NULL;
	return new_tree;
}


/**
 * @brief 	새로운 key값을 가진 노드를 생성한 후 BST에 삽입한다.
 * 			만약, 중복된 key가 이미 존재한다면 에러 메시지를 출력하고 NULL을 반환한다.
 * 
 * @param tree 			노드를 추가 할 트리의 포인터
 * @param new_key 		새로 추가 할 노드의 key 값
 * @return node_ptr 	새로 생성된 노드의 포인터
 */
node_ptr insert(tree_ptr tree, element new_key){
	node_ptr parent = NULL;
	node_ptr candidate = tree->root;

	node_ptr new_node = (node_ptr)malloc(sizeof(struct node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	new_node->key = new_key;

	// tree의 루트가 없는 경우 이 노드를 루트로 저장한 후 종료.
	if (tree->root == NULL){
		tree->root = new_node;
		return new_node;
	}
	



	
	return new_node;
}

/**
 * @brief 	BST에서 target_key값을 가진 노드를 찾아서 포인터를 반환한다.
 * 			만약, 그런 노드가 존재하지 않는다면 에러 메시지를 출력한 후 NULL을 반환한다.
 * 
 * @param tree 			검색을 수행 할 트리의 포인터
 * @param target_key 	검색 할 key값
 * @return node_ptr 	해당 key값을 가지는 노드의 포인터
 */
node_ptr find(tree_ptr tree, element target_key){
	node_ptr parent = NULL;
	node_ptr candidate = tree->root;


	return candidate;
}

/**
 * @brief 	BST에서 target_key값을 가진 노드를 찾아서 삭제 후 할당 해제한다.
 * 			만약, 그런 노드가 존재하지 않는다면 아무 행동도 하지 않는다.
 * 
 * @param tree 			검색을 수행 할 트리의 포인터
 * @param target_key 	검색 할 key값
 * @return node_ptr 	해당 key값을 가지는 노드의 포인터
 */
void delete_node(tree_ptr tree, element target_key){
	node_ptr parent;
	node_ptr candidate;

	// 해당 key값을 가진 노드가 존재하는지 검사해 본다.
	candidate = find(tree, target_key);

	if (candidate == NULL){
		// 해당 key값을 가진 노드가 존재하지 않는 경우
		return;
	}

	// 해당 key값을 가진 노드 candidate가 존재하는 경우
	parent = candidate->parent;
	
	if (candidate->left == NULL || candidate->right == NULL){
		/**************************************
		CASE 1 : candidate가 하나의 자식을 가지거나 자식을 가지지 않는 경우.
		***************************************/




		return;
	}
	else{
		/*******************************************
		CASE 2 : candidate가 정확히 두 개의 자식 노드를 가지는 경우
		********************************************/
		
		node_ptr predecessor = candidate->left;
		node_ptr parent_of_predecessor = candidate;




		return;
	}
}

/**
 * @brief 		해당 노드의 서브 트리를 in-order 순서로 출력해주는 함수
 * 				올바른 BST의 경우 in-order로 출력하면 오름차순으로 정렬되어 출력된다.
 * 				[TIP] 테스트용으로 중간 중간 사용하면 유용하다.
 * 
 * @param node 	탐색과 출력을 수행 할 노드의 포인터
 */
void print_inorder(node_ptr node){
	if (node->parent == NULL){
		printf("{ ");
	}

	if (node != NULL){
		if (node->left != NULL){
			print_inorder(node->left);
			printf(", ");
		}
		
		printf("%c", node->key);
		
		if (node->right != NULL){
			printf(", ");
			print_inorder(node->right);
		}
	}

	if (node->parent == NULL){
		printf(" }\n");
	}
}

void test_case_1(){
	tree_ptr tree = make_tree();
	
	printf("[TEST CASE #1]--------------------------\n");

	insert(tree, 'I');
	insert(tree, 'H');
	insert(tree, 'D');
	insert(tree, 'B');
	insert(tree, 'M');
	insert(tree, 'N');
	delete_node(tree, 'A');
	insert(tree, 'A');
	insert(tree, 'A');
	delete_node(tree, 'A');
	delete_node(tree, 'A');
	insert(tree, 'J');
	insert(tree, 'E');
	insert(tree, 'Q');
	insert(tree, 'A');

	print_inorder(tree->root);
	free(tree);
}

void test_case_2(){
	tree_ptr tree = make_tree();

	printf("[TEST CASE #2]--------------------------\n");

	insert(tree, 'H');
	insert(tree, 'U');
	insert(tree, 'C');
	insert(tree, 'T');
	insert(tree, 'I');
	delete_node(tree, 'A');
	insert(tree, 'B');
	insert(tree, 'C');
	insert(tree, 'M');
	insert(tree, 'D');
	insert(tree, 'Y');
	insert(tree, 'K');
	insert(tree, 'B');
	insert(tree, 'S');
	delete_node(tree, 'F');
	insert(tree, 'T');
	insert(tree, 'H');
	delete_node(tree, 'H');
	insert(tree, 'A');
	delete_node(tree, 'B');
	insert(tree, 'N');
	insert(tree, 'L');
	insert(tree, 'Q');
	delete_node(tree, 'C');
	delete_node(tree, 'D');
	insert(tree, 'O');
	insert(tree, 'F');
	insert(tree, 'D');
	insert(tree, 'E');
	insert(tree, 'A');
	insert(tree, 'W');
	insert(tree, 'V');
	delete_node(tree, 'B');
	delete_node(tree, 'E');
	delete_node(tree, 'E');
	insert(tree, 'E');
	insert(tree, 'X');
	insert(tree, 'E');
	insert(tree, 'F');
	delete_node(tree, 'F');
	insert(tree, 'S');
	insert(tree, 'V');
	insert(tree, 'Y');
	insert(tree, 'C');
	insert(tree, 'G');
	insert(tree, 'Z');
	delete_node(tree, 'C');
	delete_node(tree, 'D');
	delete_node(tree, 'H');
	insert(tree, 'W');
	delete_node(tree, 'A');
	insert(tree, 'G');
	insert(tree, 'Z');
	insert(tree, 'R');
	insert(tree, 'J');
	insert(tree, 'P');

	print_inorder(tree->root);
	free(tree);
}

int main()
{
	// 본인 학번과 이름을 출력하세요 
	printf("[Student ID] 201724516\n");
	printf("[NAME] HONG KIL-DONG\n");

	test_case_1();		// 테스트용
	//test_case_2();	// 제출용 테스트 케이스 

	return 0;
}