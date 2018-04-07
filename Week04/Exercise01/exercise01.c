#pragma disable(warning: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

/* isp and icp arrays – index is value of precedence
lparen, rparen, plus, minus, times, divide, mod, eos */
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };

/* isp: in stack precedence, icp: incoming precedence */
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

precedence stack[10];

void push(int *top, precedence token) {
	stack[++(*top)] = token;
}

precedence pop(int *top) {
	return stack[(*top)--];
}


char expression[] = "(a/(b-c+d))*(e-a)*c"; // abc-d+/ea-*c*

/**
 * @brief Get the Token object
 * 		Read a character from 'expression' and save into variable that 'symbol' indicates.
 * 		and return the corresponding enum value of that symbol.
 * 		After reading, do not forget to increase index 'n'.
 * 
 * @param symbol 		pointer to save symbol character 
 * @param n 			pointer to index of symbol in 'expression'. 
 * @return precedence 	enum value of symbol.
 */
precedence getToken(char *symbol, int *n) 
{
	*symbol = expression[(*n)++];

	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '*': return times;
	case '/': return divide;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}
}

/**
 * @brief 
 * 		Print Mathmatical Element that indicated by 'token'.
 * @param token 
 */
void printToken(precedence token) {

	char *a;

	switch (token) {
	case lparen: a = "("; break;
	case rparen: a = ")"; break;
	case plus:   a = "+"; break;
	case minus:  a = "-"; break;
	case times:  a = "*"; break;
	case divide: a = "/"; break;
	case mod:    a = "%"; break;
	default:     a = "\0";
	}

	printf("%c", *a);
}


/**
 * @brief 
 * 		Read Infix-ed expression from 'expression' array
 * 		Print out Postfix-ed expression that converted from 'expression' array.
 */
void postfix();

int main() { 
	printf("학번 201821234 이름 홍길동\n\n");
	postfix();
	getchar();

	return 0;
}


/**
* @brief
* 		Read Infix-ed expression from 'expression' array
* 		Print out Postfix-ed expression that converted from 'expression' array.
*/
void postfix() {
	char symbol;
	precedence token;

	int n = 0;
	int top = 0;
	stack[0] = eos;
	

}
