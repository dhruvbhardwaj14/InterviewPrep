#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.*/
/*Approach- 
1. Create a disjoint set for each vector in the given vector index wise
2. Create a map <string,int> storing which email is connected to what number?
3. iterate in given vector accounts and for each email map it to corresponding index disjoint set node
4. if u see any email already in the map then use disjoint set union operation on that index node
5. Go through map and in mergedMail vector first add from map all the emails at the ultimate parent of it's index. 
6. Go through merged mail and in ans at 0th column add names from accounts only for those mergedMails whose vectors not empty
6. sort vectors individually and store in final ans.
*/
class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0; i < n+1; i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUltimateParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);//path compression
    }
    void UnionByRank(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
       else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    bool isSameSet(int u,int v){
        if(findUltimateParent(u)==findUltimateParent(v)){
            return true;
        }
        else{
            return false;
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n=accounts.size();
    DisjointSet ds(n);
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            string mail=accounts[i][j];
            if(mp.find(mail)!=mp.end()){
                ds.UnionBySize(i,mp[mail]);
            }
            else{
                mp[mail]=i;
            }
        }
    }
    vector<string> mergedMail[n];
    for(auto it:mp){
        string mail=it.first;
        int node=ds.findUltimateParent(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if(mergedMail[i].size()==0) continue;
        sort(mergedMail[i].begin(),mergedMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it:mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
  
    return 0;
}