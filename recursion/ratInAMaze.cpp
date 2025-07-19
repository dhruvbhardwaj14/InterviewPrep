#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.*/

/*Approach-
1. **Function `ratInMaze(maze)`**
   * Get the size `n` of the maze (it’s an `n x n` grid).
   * Initialize an empty list `ans` to store all valid paths.
   * Create a 2D `vis` array of size `n x n` initialized with 0 to mark visited cells.
   
   * Define direction arrays:
     * `drow = [1, 0, 0, -1]` → corresponds to Down, Left, Right, Up
     * `dcol = [0, -1, 1, 0]` → column movements for each direction
   * If the starting cell `(0, 0)` is `1`, start the recursion from there using `getPath`.
   * Return the list of valid paths (`ans`).
2. **Function `getPath(i, j, n, ans, s, maze, vis, drow, dcol)`**
   * Base case
     * If current cell `(i, j)` is the destination `(n-1, n-1)`, push the current string `s` to `ans` and return.
   * Define `dir = "DLRU"` — this string gives direction labels for the four directions in the same order as `drow` and `dcol`.
3. **Loop through all 4 directions using `k = 0 to 3`:**
   * Calculate `nextRow = i + drow[k]` and `nextCol = j + dcol[k]`.
   * Check if `nextRow` and `nextCol` are within bounds.
   * Check if the cell `(nextRow, nextCol)` is unvisited and is `1` in the maze (i.e., open path).
   * If valid:
     * Mark the current cell `(i, j)` as visited: `vis[i][j] = 1`.
     * Recur to the next cell with the direction appended:
       `getPath(nextRow, nextCol, n, ans, s + dir[k], maze, vis, drow, dcol)`.
     * After recursion, backtrack by unmarking the current cell: `vis[i][j] = 0`.

### Key points to remember:
* Use direction arrays and a direction string together to manage movement and track the path string.
* Always mark the current cell as visited **before** recursion and unmark **after** recursion (backtracking).
* Only recurse into a cell if:
  * It’s inside the grid.
  * It’s not visited.
  * It’s a valid cell (`1`).
This ensures the rat only travels on open paths without revisiting the same cell in one path.
*/
void getPath(int i,int j,int n,vector<string>& ans,string s,vector<vector<int>>& maze,vector<vector<int>>& vis,int drow[],int dcol[]){
    if(i==n-1 && j==n-1){
        ans.push_back(s);
        return;
    }
    string dir="DLRU";
    for (int k = 0; k < 4; k++)
    {
        int nextRow=i+drow[k];
        int nextCol=j+dcol[k];
        if(nextRow<n && nextCol<n && nextRow>=0 && nextCol>=0 && !vis[nextRow][nextCol] && maze[nextRow][nextCol]==1){
            vis[i][j]=1;
            getPath(nextRow,nextCol,n,ans,s+dir[k],maze,vis,drow,dcol);
            vis[i][j]=0;
        }
    }
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    int n=maze.size();
    vector<string> ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    int drow[]={1,0,0,-1};
    int dcol[]={0,-1,1,0};
    if(maze[0][0]) getPath(0,0,n,ans,"",maze,vis,drow,dcol);
    return ans;
}
int main(){
  
    return 0;
}