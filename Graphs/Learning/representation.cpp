#include "bits/stdc++.h"
using namespace std;
/* 1. Adjacency Matrix- if i and j connected then a[i][j]=1 for unweighted graph and a[i][j]=weight for weighted graph in a vxv matrix 
for undirected- if a[i][j]=1 then also a[j][i]=1
for directed- if a[i][j]=1 that means there is an edge from i to j and if edge exists from j to i then it means a[j][i]=1
*/
/* 2. Adjacency List - for each of the vertices it contains a list of all vertices connected to it via edges if list of v2 has v1 then for undirected v1 list has v2 as well but for directed it's not necessary
*/

const int N=1e3+10; // we declare global variable for graph with maximum number of vertices a graph can have and because of this global behaviour all cells [i][j] of graph are 0;
int graphMatrix[N][N];

vector<int> graphList[N];// this means that graphList is an array of size N where each element is instead of int is a vector<int> in itself;
int main(){
    // Graph is always given as v-vertices(n) and e-edges(m) and taken input in that form only
    int n,m;
    cin>>n>>m;
    
    
    // For unweighted graphs input
    /* 1. Adjacency matrix input of graph 
    - high space complexity and cannot work well for vertices more than 1e3 graph types since we cannot create a matrix of more than 1e3x1e3 sizes
    - faster acces time for checking weight of i and j or if i and j connected or not. in O(1)
    */
    for (int i = 0; i < m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graphMatrix[v1][v2]=1;
        graphMatrix[v2][v1]=1;
    }
    // Space- O(n^2)

    /* 2. Adjacency List 
    - optimised space complexity
    - increased time complexity for checking weight of i and j or if i and j connected or not. in O(n)
    */
    for (int i = 0; i < m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graphList[v1].push_back(v2);
        graphList[v2].push_back(v1);
    }
    // Space- O(n+m)

    
    // For weighted graphs input
    /* 1. Adjacency matrix input of graph 
    - high space complexity and cannot work well for vertices more than 1e3 graph types since we cannot create a matrix of more than 1e3x1e3 sizes
    - faster acces time for checking weight of i and j or if i and j connected or not. in O(1)
    */
    for (int i = 0; i < m; i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graphMatrix[v1][v2]=wt;
        graphMatrix[v2][v1]=wt;
    }
    // Space- O(n^2)

    /* 2. Adjacency List 
    - optimised space complexity
    - increased time complexity for checking weight of i and j or if i and j connected or not. in O(n)
    */
    vector<pair<int,int>> graphList[N];//array of size N where each element is a pair of vector
    for (int i = 0; i < m; i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graphList[v1].push_back({v2,wt});
        graphList[v2].push_back({v1,wt});
    }
    // Space- O(n+m)
    return 0;
}