#include <iostream>
#include <math.h>
#include "StackCalls.h";

using namespace std;

void solvePuzzle(int puzzle [][4], int row, int col);
bool isSafePlace(int puzzle[][4], Stack *rows, Stack *colms, int i, int col);
void Display(int puzzle[][4]);
void main() {
	int puzzle[4][4] = { 
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 }
					};
	solvePuzzle(puzzle, 4, 0);
	getchar();
}
void solvePuzzle(int puzzle[][4], int row, int col) {
	Stack rows, colms;
	int j=0;
	bool backtrack = true;
		if (isSafePlace(puzzle, &rows, &colms, j, col))
		{
			rows.push(j, &rows);
			colms.push(col, &colms);
			puzzle[j][col] = 1;
			col++;
			while (col < 4)
			{
				while (j < 4)
				{
					backtrack = true;
					if (isSafePlace(puzzle, &rows, &colms, j, col))
					{
						backtrack = false;
						rows.push(j, &rows);
						colms.push(col, &colms);
						puzzle[j][col] = 1;
						j = 0;
						break;
					}
					j++;
				}
				if (backtrack == true) {
					rows.pop(&row, &rows);
					colms.pop(&col, &colms);
					puzzle[row++][col--] = 0;
					j = row;
				}
				col++;
			}
	}
		Display(puzzle);
}
bool isSafePlace(int puzzle[][4], Stack *rows, Stack *colms, int i, int col)
{
	int row, cols;
	rows->StackTop(&row, rows);
	colms->StackTop(&cols, colms);
	for (int j = 0; j < col; j++)
	{
		if (puzzle[i][j])
			return false;
		else
		{
			if (abs(row - i) == abs(cols - col))
				return false;
		}
	}
	
	return true;
}
void Display(int puzzle[][4]) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << puzzle[i][j] << " " ;
		}
		cout << endl;
	}
}