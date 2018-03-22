#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>

#define MAX_STRING_LENGTH  10000
#define MAX_PATTERN_LENGTH 1000

/**
 * @brief 
 * 
 * @param pat 
 * @param pi 
 */
void fail(char* pat, int* pi);

/**
 * @brief 
 * 
 * @param string 
 * @param pattern 
 * @param pi 
 * @return int 
 */
int pmatch(char *string, char *pattern, int* pi);


void main() 
{
	printf("학번 201821234 이름 홍길동\n\n");
	int pi[MAX_PATTERN_LENGTH] = { 0, };
	char string[] = "Ajou university is the best in the world. AaBaaBaCababbaababababbabsdcbbacbacbacbaaabbaaaabaabacaabbcdasdasdasdaaabaabac";
	char pattern[] = "aabaabac";

	fail(pattern, pi);
	int matched_index = pmatch(string, pattern, pi);

	if (matched_index == -1) {
		printf("No pattern found");
	}
	else {
		printf("Index of the first pattern found: %d", matched_index);
	}

	getchar();
}

void fail(char* pat, int* pi) 
{
	//fill this code
	
}

int pmatch(char *string, char *pattern, int* pi) 
{
	//fill this code


}