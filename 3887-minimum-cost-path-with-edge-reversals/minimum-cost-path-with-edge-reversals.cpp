class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
   
         vector<vector<pair<int,int>>> adj(n);
        for (auto it : edges) {
            int x = it[0], y = it[1], cost = it[2];
            adj[x].push_back({y, cost});
            adj[y].push_back({x, 2 * cost});
        }
        vector<int> vis(n, 0);
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [cost, node] = pq.top(); pq.pop();
            if (vis[node]) continue;
            vis[node] = true;
            if (node == n - 1) return cost;
            for (auto [ch, cos] : adj[node]) {
                if (dist[ch] > cost + cos) {
                    dist[ch] = cost + cos;
                    pq.push({dist[ch], ch});
                }
            }
        }
        return -1;

    }
};