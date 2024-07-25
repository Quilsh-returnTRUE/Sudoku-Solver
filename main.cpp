#include <iostream>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>
#include <sstream>


const int GRID_SIZE = 9;
int grid[GRID_SIZE][GRID_SIZE];


bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE]);

bool findEmptyCell(int grid[GRID_SIZE][GRID_SIZE], int& row, int& col);

bool isValidPlacement(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num);

void printGrid(int grid[GRID_SIZE][GRID_SIZE]);


bool readGridFromInput()
{
	std::cout << "Enter the Sudoku grid (9 lines, each containing 9 numbers separated by spaces):\n";
	for (int i = 0; i < GRID_SIZE; ++i)
	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream iss(line);
		for (int j = 0; j < GRID_SIZE; ++j)
		{
			if (!(iss >> grid[i][j]))
			{
				std::cout << "Invalid input. \n";
				return false;
			}
		}
	}
	return true;
}




int main()
{
	if (!readGridFromInput())
	{
		return 1;
	}


	std::cout << "Initial sudoku grid:\n";
	printGrid(grid);

	if (solveSudoku(grid))
	{
		std::cout << "\n Sudoku Solved:\n";
		printGrid(grid);
	}
	else
		std::cout << "Could not find a solution for this grid :(\n";



	return 0;
}


void printGrid(int grid[GRID_SIZE][GRID_SIZE])
{
	{
		for (int i = 0; i < GRID_SIZE; ++i)
		{
			if (i % 3 == 0 && i != 0)
			{
				std::cout << "------+-------+-------\n";
			}
			for (int j = 0; j < GRID_SIZE; ++j)
			{
				if (j % 3 == 0 && j != 0)
				{
					std::cout << "| ";
				}
				if (grid[i][j] == 0)
				{
					std::cout << ". ";
				}
				else
					std::cout << grid[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}

bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE])
{
	int row, col;
	if (!findEmptyCell(grid, row, col)) {
		return true;
	}

	for (int num = 1; num <= 9; num++)
	{
		if (isValidPlacement(grid, row, col, num))
		{
			grid[row][col] = num;

			if (solveSudoku(grid))
			{
				return true;
			}

			grid[row][col] = 0;
		}
	}
	return false;
}

bool findEmptyCell(int grid[GRID_SIZE][GRID_SIZE], int& row, int& col)
{
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (grid[row][col] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

bool isValidPlacement(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num)
{
	//check row
	for (int c = 0; c < 9; c++)
	{
		if (grid[row][c] == num)
		{
			return false;
		}
	}


	//check column
	for (int r = 0; r < 9; r++)
	{
		if (grid[r][col] == num)
		{
			return false;
		}
	}

	int startRow = row - row % 3;
	int startCol = col - col % 3;
	for (int r = startRow; r < startRow + 3; r++)
	{
		for (int c = startCol; c < startCol + 3; c++)
		{
			if (grid[r][c] == num)
			{
				return false;
			}
		}
	}

	return true;

}
