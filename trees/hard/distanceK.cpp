#include "bits/stdc++.h"
using namespace std;
//Problem Statement
/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
*/
/*Approach- 
Step 1 – Build a parent map
   - Traverse the tree (DFS or BFS) starting from the root.
   - For each node, store its parent in a map:
       parent[node] = parent_node
   - Root’s parent will be nullptr.
   - This allows moving from a node to its parent in O(1) time.

Step 2 – BFS starting from the target node
   - Use a queue to perform BFS from the target node.
   - Keep a visited set to avoid revisiting nodes.
   - At each step, you can move:
       - Left child (if exists and not visited)
       - Right child (if exists and not visited)
       - Parent (if exists and not visited)

Step 3 – Stop at distance k
   - Maintain a distance counter during BFS.
   - When distance == k, stop expanding further.
   - All nodes remaining in the queue are exactly k distance from the target.

Step 4 – Collect results
   - Extract all node values from the queue.
   - Return them as the answer (order does not matter).
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void buildParentMap(TreeNode* node, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!node) return;
    parent[node] = par;
    buildParentMap(node->left, node, parent);
    buildParentMap(node->right, node, parent);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent; // store parent pointers
    buildParentMap(root, nullptr, parent);

    unordered_set<TreeNode*> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited.insert(target);

    int dist = 0;
    while (!q.empty()) {
        int size = q.size();
        if (dist == k) break; // stop at distance k
        dist++;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // Check left child
            if (node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                q.push(node->left);
            }
            // Check right child
            if (node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                q.push(node->right);
            }
            // Check parent
            if (parent[node] && !visited.count(parent[node])) {
                visited.insert(parent[node]);
                q.push(parent[node]);
            }
        }
    }

    // All nodes left in queue are at distance k
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front()->val);
        q.pop();
    }
    return result;
}
int main(){
  
    return 0;
}