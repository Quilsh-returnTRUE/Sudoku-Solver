# Sudoku-Solver
Instant Sudoku Solver in C++

This Sudoku solver using recursive backtracking to solve the puzzle :D
It works by trying all potential solutions by trying each options recursively, and backtracking when a solution can't be found

Most people like a language like python in a project like this, but you know that c++ > python bc how fucking speedy it is. I started this off in 
python then thought"what the hell am i doing, i know c++"


First, it tries placing numbers (1-9) in each empty "cell"
It checks if placing anumber at a certain cell violates any rules(row, colum, or subgrid)
If a number can be placed without violating the rules, it recursively tries to solve the rest of the grid

Remember the rules of sudoku it must follow are:
* Each row & column must contain the numbers from 1 to 9, without repetitions
* The digits can only occur once per block(nonet)
* The sum of every single row, column, and nonet must equal 45

Detailed steps:
* Find empty cell: locate the next empty cell in the grid
* Try each number: for the empty cell, try each number from 1-9
* Validate placement: check if placing the number in the cell satisfies all rules
* recursively siolve: if its valid, call the solver function to solve the remaining grid
* backtrack: if no number can be placed that satisfies all constraints, backtrack by undoing the current placement and then it tries the next number
