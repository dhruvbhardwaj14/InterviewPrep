#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 10^4
*/
/*Approach-
sort the array given based on their first members i.e. start times and then check the finish times of each of the member and compare it with start time of next and if finish>start then update finish with max of finish and next item's finish time. push to answer once we do not get anymore finish>start.
*/
bool sortInterval(vector<int> v1,vector<int> v2){
    return v1[0]<v2[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n,vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>intervals[i][j];
        }
    }
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end(),sortInterval);
    for (int i = 0; i < intervals.size(); i++)
    {
        int start=intervals[i][0];
        int finish=intervals[i][1];
        while (i<intervals.size()-1 && finish>=intervals[i+1][0])
        {
            finish=max(finish,intervals[i+1][1]);
            i++;
        }
        cout<<endl;
        ans.push_back({start,finish});
    }
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}