#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/
/*Approach- 
transpose the matrix
then reverse every row 
*/
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int> > matrix(m,vector<int>(n)) ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    // transpose the matrix - swap elements i j to j i were i!=j for each row start from i+1 to n-1
    for (int i = 0; i < m-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(i!=j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    // reverse
    for (int i = 0; i < m; i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    // print
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}