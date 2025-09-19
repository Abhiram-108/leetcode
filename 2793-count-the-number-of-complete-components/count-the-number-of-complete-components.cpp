class Solution {
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node, vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs(adj, vis, it, component);
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int countComplete = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> component;
                dfs(adj, vis, i, component);

                int nodes = component.size();
                long long edgeCount = 0;

                for (int node : component) {
                    edgeCount += adj[node].size();
                }

                edgeCount /= 2; // because each edge counted twice

                if (edgeCount == (long long)nodes * (nodes - 1) / 2)
                    countComplete++;
            }
        }

        return countComplete;
    }
};
