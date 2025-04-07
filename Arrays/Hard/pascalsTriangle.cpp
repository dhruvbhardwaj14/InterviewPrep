#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
/*Approach- 
each row of pascal's triangle has first element as 1 and then rest elements are calculated as
i->1 to numRows
j->1 to i
ans= (ans*(i-j))/j;
*/
int main(){
    int numrows;
    cin>>numrows;
    vector<vector<int> > v;
    for (int i = 1; i <=numrows; i++)
    {
        vector<int> temp;
        temp.push_back(1);
        int ans=1;
        for (int j = 1; j < i; j++)
        {
            ans=ans*(i-j);
            ans=ans/j;
            temp.push_back(ans);
        }
        v.push_back(temp);
    }
    for (auto it : v)
    {
        for (auto i : it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
    
    
    return 0;
}