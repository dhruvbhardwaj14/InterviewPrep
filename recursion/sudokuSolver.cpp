#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.*/
/*Approach-
#### ✅ Step 1: `isValid()` function – to check if placing a number is safe
1. **Loop `i` from 0 to 8** to check:
   * If the number `c` already exists in the same **column** → `board[i][col] == c`
   * If the number `c` already exists in the same **row** → `board[row][i] == c`
   * If the number `c` already exists in the same **3x3 subgrid**:
     * Get the top-left starting index of the 3x3 block using:
       `3 * (row / 3)` and `3 * (col / 3)`
     * Check subgrid cell by:
       `board[3*(row/3) + i/3][3*(col/3) + i%3] == c`
2. **Return `false`** if number already exists in any of the three checks.
3. **Return `true`** if number `c` can be safely placed.


#### 🔄 Step 2: `solve()` function – recursive backtracking logic
1. Loop over each **cell of the board** using two nested loops:
   * Outer loop: rows `i = 0 to 8`
   * Inner loop: columns `j = 0 to 8`
2. **Check if current cell is empty** i.e., `board[i][j] == '.'`

3. If yes:
   * Try all digits from `'1'` to `'9'` in this cell
   * For each digit `c`:
     * Use `isValid()` to check if placing `c` is valid
     * If valid:
       * Place `c` in the cell → `board[i][j] = c`
       * Recur to solve the rest of the board → `solve(board)`
       * If recursive call returns true → puzzle solved → return true
       * If not → backtrack → reset the cell to `'.'`
   * If none of the digits work, return `false` → trigger backtracking
4. If all cells are filled (i.e., no empty `'.'` found), return `true`

### 🧠 Summary of Logic
* **Try placing** digits `1-9` in **every empty cell**
* **Validate** the digit using `isValid()`
* **Backtrack** if placement doesn’t lead to a solution
* **Base case**: No empty cell remains → solved


### 🧩 Recap Key Concepts
* Backtracking → explore all choices, revert if invalid
* Sudoku constraints: Row, Column, 3x3 box
* Recursive structure helps auto-backtrack
*/
bool isValid(vector<vector<char>>& board,int row,int col,char c){
    for (int i = 0; i < 9; i++)
    {
        if(board[i][col]==c) return false;
        if(board[row][i]==c) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    int n=board.size();
    int m=board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j]=='.'){
                for (char c = '1'; c <='9'; c++)
                {
                    if(isValid(board,i,j,c)){
                        board[i][j]=c;
                       if(solve(board)==true) return true;
                       else board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
int main(){
  
    return 0;
}