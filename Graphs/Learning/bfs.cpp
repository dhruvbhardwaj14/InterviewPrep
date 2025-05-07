#include "bits/stdc++.h"
using namespace std;
/* BFS 
- adjacency list is best
- used to find shortest path
- O(v+e)
*/
const int N=1e5+10;
vector<int> graph[N];
int visited[N];
int level[N];
void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source]=1;
    while (!q.empty())
    {
        int cur_vertex=q.front();
        q.pop();
        cout<<cur_vertex<<" ";
        for(int child:graph[cur_vertex]){
            if(!visited[child]){
                q.push(child);
                visited[child]=1;
                level[child]=level[cur_vertex]+1;
            }
        }
    }
    
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    cout<<endl;
    for (int i = 1; i <=n; i++)
    {
        cout<<i<<" : "<<level[i]<<endl;
    }
    
    return 0;
} 