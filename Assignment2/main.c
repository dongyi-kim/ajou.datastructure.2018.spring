#pragma warning(disable: 4996)
#include<stdio.h>

#include "main.h"


// 아래 상수를 수정하여 테스트 데이터를 변경할 수 있습니다
#define DATA_FOLDER "sample01"

int main(void){
	graph* spanning_tree;
	graph* graph;
	graph = read_graph(DATA_FOLDER);

	spanning_tree = find_minimum_spanning_tree(graph);

	write_graph(DATA_FOLDER, spanning_tree);

	release_graph(graph);
	release_graph(spanning_tree);

	return 0;
}