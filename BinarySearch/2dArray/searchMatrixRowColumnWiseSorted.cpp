#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.*/
/*Approach- */
int main(){
    int m,n,target;
    cin>>m>>n>>target;
    vector<vector<int>> matrix(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; i++)
        {
            cin>>matrix[i][j];
        }
    }
    
    return 0;
}