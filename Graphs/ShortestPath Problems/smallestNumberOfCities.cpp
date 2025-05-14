#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.s*/
/*Approach-
1. Run Floyd warshall in each node 
2. iterate in each row of dist and check is dist less than equal to threshold
3. update ans
4. return at end of all iterations so it stores the greater number always
*/
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n,vector<int>(n,1e5));
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        dist[u][v]=w;
        dist[v][u]=w;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j) dist[i][j]=0;
        }
        
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][k]!=1e5 && dist[k][j]!=1e5)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int ans=-1;
    int currCnt=INT_MAX;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(dist[i][j]<=distanceThreshold){
                cnt++;
            }
        }
        if(cnt<=currCnt){
            currCnt=cnt;
            ans=i;
        }
    }
    return ans;
}
int main(){
  
    return 0;
}