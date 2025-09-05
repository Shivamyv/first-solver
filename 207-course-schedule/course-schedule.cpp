class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);

        // Calculate in-degrees
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        // Build graph
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);  // v → u
        }

        // Run topo sort
        vector<int> topo = topoSort(numCourses, adj);

        // If topo sort doesn't include all courses → cycle exists
        return topo.size() == numCourses;
    }
};
