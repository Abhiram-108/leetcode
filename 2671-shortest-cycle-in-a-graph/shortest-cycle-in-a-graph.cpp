class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 1e9;

        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if (parent[u] != v) {
                        // Found a cycle
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (ans == 1e9) ? -1 : ans;
    }
};
