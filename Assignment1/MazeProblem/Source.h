#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>


#ifndef SOURCE_H
#define SOURCE_H

/**
 * @brief   Folder name to load as data
 *			- #define DATA_FOLDER "data_sample"
 *			- #define DATA_FOLDER "data_test_01"
 *			- #define DATA_FOLDER "data_test_02"
 *			- #define DATA_FOLDER "data_test_03"
 */
#define DATA_FOLDER "data_sample"

typedef int** Map;

#define FILE_NAME_INPUT  "input.txt"
#define FILE_NAME_OUTPUT "output.txt"

#ifdef _WIN32
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

double BEGIN_TIME = 0.0;

#define TIME_LIMIT_SECONDS 10.f
#define TIME_COST (  (clock() - BEGIN_TIME) / CLOCKS_PER_SEC )

/**
 * @brief 
 * 	Time check function.
 *  If your program doesn't stop in Time Limit,
 *  This function will raise assertion error.
 * 
 */
void time_check()
{
	printf("\rTIME COST : %.5lf seconds", TIME_COST);
	if (TIME_COST > TIME_LIMIT_SECONDS)
	{
		assert(TIME_COST <= TIME_LIMIT_SECONDS);
		printf("\n\nTIME LIMIT EXCEEDED !!!\n");
		exit(-1);
	}
}


/**
 * @brief 
 *	Initialize NxN array and fill 0s to it.
 * 
 * @param map 
 * @param N 
 */
void init_map(Map* map, int N)
{
	int i;
	int j;
	*map = (int**)malloc(sizeof(int*)*N);
	for (i = 0; i < N; i++)
	{
		(*map)[i] = (int*)malloc(sizeof(int)*N);
		for (j = 0; j < N; j++)
		{
			(*map)[i][j] = 0;
		}
	}
}

/**
 * @brief 
 * 		- Copy all elements from 'src' to 'dest' 
 *
 * @param src 
 * @param dest 
 * @param N 
 */
void copy_map(Map src, Map dest, int N)
{
	int row, column;
	for (row = 0; row < N; row++)
	{
		for (column = 0; column < N; column++)
		{
			dest[row][column] = src[row][column];
		}
	}
}

/**
 * @brief 
 *		- initialize maze and path map (NxN 2D array)
 *		- read input file and save into 'maze'
 * 
 * @param maze 
 * @param path 
 * @param N 
 */
void init_and_input_maze(Map* maze, Map* path, int* N)
{
	FILE* fin;
	int row, column;
	char input_path[1000];
	sprintf(input_path, "%s%s%s", DATA_FOLDER, PATH_SEPARATOR, FILE_NAME_INPUT);
	fin = fopen(input_path, "r");
	BEGIN_TIME = clock();
	if (fin == NULL)
	{
		printf("[!] INPUT FILE DOES NOT EXIST");
		exit(-1);
	}

	fscanf(fin, "%d", N);

	init_map(maze, *N);
	init_map(path, *N);

	for (row = 0; row < *N; row++)
	{
		for (column = 0; column < *N; column++)
		{
			fscanf(fin, "%d", &((*maze)[row][column]) );
		}
	}
	fclose(fin);
}

/**
 * @brief 
 *		- Free 2D array 
 * 
 * @param map 
 * @param N 
 */
void release_map(Map map, int N)
{
	int row;
	for (row = 0; row < N; row++)
	{
		free(map[row]);
	}
	free(map);
}

int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, 1, -1, 0 };
/**
 * @brief 
 *		- Save your 'path' as answer into 'output.txt' 
 *
 * @param path 
 * @param path_exist 
 * @param N 
 */
void save_result(Map path, bool path_exist, int N)
{
	FILE* fout;
	Map original_map, empty;
	char output_path[1000];
	int row, column;
	int i;
	int linked;
	int length = 0;
	int failed = 0;
	sprintf(output_path, "%s%s%s", DATA_FOLDER, PATH_SEPARATOR, FILE_NAME_OUTPUT);
	fout = fopen(output_path, "w+");

	init_and_input_maze(&original_map, &empty, &N);

	if (path_exist == false)
	{
		fprintf(fout, "NO PATH EXISTS\n");
	}
	else{
		fprintf(fout, "PATH EXIST\n");

		for (row = 0; row < N; row++)
		{
			for (column = 0; column < N; column++)
			{
				if (path[row][column] == 1)
				{
					length += 1;
				}
			}
		}

		fprintf(fout, "PATH LENGTH : %d\n", length);
		fprintf(fout, "\n");

		for (row = 0; row < N; row++)
		{
			for (column = 0; column < N; column++)
			{
				if(path[row][column] == 1)
				{
					linked = 0;
					for(i = 0; i < 4 ; i++)
					{
						if(row+dr[i] < 0 || row+dr[i] >= N || column + dc[i] < 0 || column + dc[i] >= N)
							continue;
						if (path[row + dr[i]][column + dc[i]] == 1 && original_map[row + dr[i]][column + dc[i]] == 0)
						{
							linked += 1;
						}
					}
					if (original_map[row][column] == 0 && (linked > 0 || N == 1))
					{
						fprintf(fout, "O");
					}else{
						fprintf(fout, "X");
						failed += 1;
					}
				}else{
					if (original_map[row][column] == 0)
					{
						fprintf(fout, ".");
					}
					else
					{
						fprintf(fout, "#");
					}
				}
			}
			fprintf(fout, "\n");
		}

		if (failed > 0)
		{
			fprintf(fout, "\n");
			fprintf(fout, "The number of invalid path Characters (X) : %d\n", failed);
		}
	}
	
	fclose(fout);
	free(original_map);
}

#endif