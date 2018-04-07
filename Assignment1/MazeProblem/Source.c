#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdbool.h>
#include "Source.h"



/** ASSIGNMENT NOTICE ***************************************************
*
*		# Fill or modify below two function
*			- isSafe()
*			- solveMazeUtil()
*
*		# DO NOT MODIFY ANY FUNCTIONS IN HEADER FILE "SOURCE.H"
*           - But you can modify "DATA_FOLDER" constant string only to specify your data folder to load.
*			- #define DATA_FOLDER "data_sample"
*			- #define DATA_FOLDER "data_test_01"
*			- #define DATA_FOLDER "data_test_02"
*			- #define DATA_FOLDER "data_test_03"
*
*		# solveMazeUtil() function MUST BE IMPLEMENTED ONLY IN RECULSIVE METHOD.
* 
*       # You should use isSafe() function in order to check maze[r][c].
*           - DO NOT implement same logics in solveMazeUtil() function. 
*           - If not, your score will be downgraded.
*/


bool isSafe(Map maze, int r, int c, Map path, int N);
bool solveMazeUtil(Map maze, int r, int c, Map path, int N, int length);

/**
* @brief
* 		# function to print 2d step matrix in console
*
* @param sol 	# 2d-array of path (solution path should be marked as 1)
*/
void printMap(Map map, int N)
{
	int r, c;
	printf("-----------------\n");
	for (r = 0; r < N; r++)
	{
		for (c = 0; c < N; c++)
		{
			printf("%3d", map[r][c]);
		}
		printf("\n");
	}
	printf("-----------------\n");
}


//If you want to save your path temporarily, declare global one like below.
//Map answerPath;

int main()
{
	int N;
	Map maze; // "Map" is identically same as "int**"
	Map path; // "typedef int** Map" is declared in header file
	bool path_exist = false;

	//Initialize all NxN array elements to 0.
	//And read maze information
	init_and_input_maze(&maze, &path, &N);

	// You can declare more map variables if you want like below.
	//init_map(&answerPath, N);
	
	//Find paths from (0, 0) to (N-1, N-1)
	if (solveMazeUtil(maze, 0, 0, path, N, 1) == true)
	{
		path_exist = true;
	}
	else
	{
		printf("Solution doesn't exist");
	}

	//Save your answer into output.txt
	// - You can save your own map as answer like "save_result(answerPath, path_exist, N);"
	save_result(path, path_exist, N);

	//Release all memory
	release_map(maze, N);
	release_map(path, N);
	//release_map(answerPath, N);

	return 0;
}

/**
 * @brief
 * 		# function to determine some position is safe or not
 *
 * @param maze 		# 2d-array of maze (passable way are marksed as 0)
 * @param r			# current position in Rows.
 * @param c 			# current position in Columns.
 * 						# This function determines whether maze[r][c] is valid or not.
 *
 * @param path 		# 2d-array of path (solution path should be marked as 1)
 * @param N 		# Map size 
 *
 * @return true 	# return when position (row=r, col=c) is passable and exists on the map
 * @return false 	# return else
 */
bool isSafe(Map maze, int r, int c, Map path, int N)
{
	time_check(); // DO NOT REMOVE OR MOVE THIS STATEMENT
	// if (r,c outside maze) return false
	if (c >= 0 && c < N && r >= 0 && r < N && maze[r][c] == 0)
		return true;

	return false;
}

/**
 * @brief 
 * 		# Recursive function to search path to goal recursively.
 * 
 * @param maze 		# 2d-array of maze (passable way are marked as 0)
 * @param r			# current position in Rows.
 * @param c 		# current position in Columns.
 *	 					# This function acts like stand on maze[r][c]
 * @param path 		# 2d-array of path (solution path should be marked as 1)
 * @param N 		# Map size 
 * @param length    # length of your path (number of visited cells)
 *
 * @return true 	# return when you can find a valid path from here to goal.
 * @return false  	# return when you can not find any valid paths from here to goal.
 */
bool solveMazeUtil(Map maze, int r, int c, Map path, int N, int length)
{
	time_check(); // DO NOT REMOVE OR MOVE THIS STATEMENT
	
	// if ( current position is goal) return true
	if (r == N - 1 && c == N - 1)
	{
		path[r][c] = 1;
		//If you want to save your path temporarily, copy your path into another one, like below.
		//copy_map(path, answerPath, N);
		return true;
	}

	// Check if maze[r][c] is valid
	if (isSafe(maze, r, c, path, N) == true)
	{
		// mark r,c as part of solution path
		path[r][c] = 1;

		/* [1] Try to move upward in rows */
		if (solveMazeUtil(maze, r + 1, c, path, N, length + 1) == true)
			return true;

		//when no paths in upward..
		/* [2] Try to move rightward in columns */
		if (solveMazeUtil(maze, r, c + 1, path, N, length + 1) == true)
			return true;

		/* If none of the above movements work then BACKTRACK:
		unmark r,c as part of solution path */
		path[r][c] = 0;
	}

	return false;
}

