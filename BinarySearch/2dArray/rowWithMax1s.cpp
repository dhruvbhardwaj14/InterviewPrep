#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.
*/

/*Approach- traverse row wise and for each row check first occurence of 1 using lowerbound and the count will be just total minus first occurence and update maxcnt*/
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>matrix[i][j];
        }
    }
    int maxcnt=INT_MIN,ans=-1,counter=1;
    for (int i = 0; i < n; i++)
    {
        int occ=lower_bound(matrix[0].begin(),matrix[0].end(),1)-matrix[0].begin();
        int diff=m-occ;
        if(maxcnt<diff){
            ans=i;
            maxcnt=diff;
        }
        else if(maxcnt==diff){
            counter++;
        }
    }
    if(counter==n){ // if all rows are 1's then this condition prints 1
        cout<<-1<<endl;
    }
    else cout<<ans<<endl;
    
    return 0;
}