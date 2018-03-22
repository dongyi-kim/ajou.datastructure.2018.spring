#pragma warning(disable: 4996)
#include <stdio.h>
#define MAX(a,b) ( (a>b) ? (a):(b) )
#define MIN(a,b) ( (a<b) ? (a):(b) )

#define MAX_DEGREE 50

typedef struct {             // Define polynomial structure
	int degree;              // maximum degree of x 
	float coef[MAX_DEGREE];  
} polynomial;

/**
 * @brief 
 *  return new Polynomial C(x) = A(x) + B(x) 
 *
 * @param A 
 * @param B 
 * @return polynomial 
 */
polynomial addPoly(polynomial A, polynomial B);

/**
 * @brief 
 *  print P(x) in console like below 
 *   Example> 5x^5 + 7x^3 + 2x^1 + x + 0
 * @param P 
 */
void printPoly(polynomial P);

void main() 
{
	printf("학번 201821234 이름 홍길동\n\n");
	
	/**
	 * @brief 
	 *  initialize polynomial A 
	 *  A(x) = 4x^3 + 3x^2 + 5x + 0
	 */
	polynomial A = { 3,{ 4,3,5,0 } }; 

	/**
	 * @brief 
	 * initialize polynomial B
	 * B(x) = 3x^4 + x^3 + 2x + 1
	 */
	polynomial B = { 4,{ 3,1,0,2,1 } };  // initialize polynomial B

	polynomial C;
	C = addPoly(A, B);   // Add A and B

	printf("A(x) = ");  printPoly(A);   // Print polynomial A
	printf("B(x) = ");  printPoly(B);   // Print polynomial B
	printf("C(x) = ");  printPoly(C);   // Print polynomial C

	getchar();
}


polynomial addPoly(polynomial A, polynomial B) 
{
	polynomial C ;
	//Fill this code

	return C;
}

void printPoly(polynomial P) 
{

	//fill this code
}