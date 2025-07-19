#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an array arr and target sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals the given target sum(k).
*/
/*Approach- */
void getSumSubSequence(int idx,int n,vector<int>& arr, int k,bool& isSumTrue){
    if(k==0){
        isSumTrue=true;
        return;
    }
    if(idx>=n) return;
    k-=arr[idx];
    getSumSubSequence(idx+1,n,arr,k,isSumTrue);
    k+=arr[idx];
    getSumSubSequence(idx+1,n,arr,k,isSumTrue);

}
bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    bool isSumTrue=false;
    getSumSubSequence(0,n,arr,k,isSumTrue);
    return isSumTrue;
}
int main(){
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3}, 5},        // true (2+3)
        {{1, 2, 3}, 0},        // true (empty subsequence)
        {{3, 34, 4, 12, 5, 2}, 9}, // true (4+5)
        {{1, 1, 1, 1}, 5},     // false
        {{10, 20, 30}, 60},    // true (10+20+30)
        {{1, 3, 5}, 2},        // false
        {{2, 4, 6, 8}, 14},    // true (6+8)
        {{5}, 5},              // true (only element)
        {{5}, 0},              // true (empty subsequence)
        {{5}, 10}              // false
    };

    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> arr = testCases[i].first;
        int k = testCases[i].second;
        bool result = checkSubsequenceSum(arr.size(), arr, k);
        cout << "Test case " << i + 1 << ": ";
        cout << (result ? "True" : "False") << endl;
    }
    return 0;
}