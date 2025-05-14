#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 10^8. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed

*/
/*
Approach- 
- It also works for negative edges and negative cycle
- it only works for directed graphs
but if unidrected graphs given then?- make each unidrected edge from u to v as directed edges of u to v and v to u of same edge weights

Algo:-
- Relax all the edges n-1 times sequentially. 
q. Why n-1?
ans since we have n-1 edges in worst case that means that node at bottom is the first one to be updated so n-1 iterations will it take to relax all the edges
q. how to detect negative cycle?
ans if at nth iteration still a relaxation happens that means there is a negative weight cycle.
*/

int main(){
  
    return 0;
}