Priority queue implementation.(min heap)
-DEFAULT MAX HEAP
    priority_queue<pair<int, int>> pq;
-Min-Heap — Smallest pair at top:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
it has queue.top() instead queue.front();