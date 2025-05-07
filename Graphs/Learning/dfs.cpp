#include "bits/stdc++.h"
using namespace std;
/* Dfs
- Adjacency List representation is best
- DFS code has 4 sections where u can write the code
- O(v+e)
*/
const int N=1e5+10;
vector<int> graph[N];

bool visited[N];// visited array
void dfs(int vertex){
    // 1. section - takes action on vertex after entering the vertex
    // if(visited[vertex]) return;  // this can be used instead of visited child code in loop
    visited[vertex]=true;
    cout<<vertex<<endl;
    for (int child : graph[vertex]){
        cout<<"Parent: "<<vertex<<" Child: "<<child<<endl;
        if(visited[child]) continue;
        // 2. section - takes action on child node before entering the child node basically subtree ke ander enter krne se pehle kya code kr skte ho
        dfs(child);
        // 3. section - takes action on child node after entering the child node basically subtree se vapas aate hue jo krna h code vo idhr kr skte ho
    }
    // 4. section - takes action on vertex before exiting the vertex basically saare child uss node ke compute krliye ab un sbka kuch nikalna h together 
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    return 0;
}