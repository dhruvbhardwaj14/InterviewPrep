#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*/

/*Approach- 
1. **Create a helper function `isSafe(row, col, board, n)`**
   * This function checks if it is safe to place a queen at position `(row, col)`.
2. **Inside `isSafe`:**
   * **Check upper-left diagonal:** Move `row--` and `col--` until either becomes negative. If a `'Q'` is found, return `false`.
   * **Check lower-left diagonal:** Move `row++` and `col--` until `row < n` and `col >= 0`. If a `'Q'` is found, return `false`.
   * **Check left row:** Move `col--` in the same `row`, and if any cell has `'Q'`, return `false`.
   * If no conflicts found, return `true`.
3. **Create recursive function `getQueen(col, board, ans, n)`**
   * Base case: If `col == n`, it means all queens are placed. Add the current `board` configuration to `ans` and return.
   * Recursive case:
     * For every `row` from `0` to `n-1`:
       * If placing queen at `(row, col)` is safe:
         * Place `'Q'` at `(row, col)`.
         * Recurse to the next column using `getQueen(col + 1, board, ans, n)`.
         * Backtrack by resetting `(row, col)` to `'.'`.
4. **Main function `solveNQueens(n)`**
   * Initialize `ans` as a list of solutions.
   * Initialize `board` as a list of `n` strings, each with `n` dots (`.`).
   * Call the recursive function `getQueen(0, board, ans, n)` to start placing queens from column 0.
   * Return `ans`.
*/
bool isSafe(int row,int col,vector<string>& board,int n){
    // check upper diagonals
    int duprow=row;
    int dupcol=col;

    while (row>=0 && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    col=dupcol;
    row=duprow;
    while (row<n && col>=0)
    {
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    }
    col=dupcol;
    row=duprow;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    return true;
}
void getQueen(int col,vector<string>& board,vector<vector<string>>& ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(isSafe(i,col,board,n)){
            board[i][col]='Q';
            getQueen(col+1,board,ans,n);
            board[i][col]='.';
        }
    }
    
}
vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for (int i = 0; i < n; i++)
        {
            board[i]=s;
        }
        getQueen(0,board,ans,n);
        return ans;

}
int main(){
  
    return 0;
}