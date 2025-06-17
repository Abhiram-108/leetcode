class Solution {
    int timer = 0;

    void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj,
             vector<int>& time, vector<int>& low_time, vector<vector<int>>& bridges) {

        vis[node] = 1;
        time[node] = low_time[node] = timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, vis, adj, time, low_time, bridges);
                low_time[node] = min(low_time[node], low_time[it]);

                if (low_time[it] > time[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                low_time[node] = min(low_time[node], time[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> time(n, 0);
        vector<int> low_time(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, time, low_time, bridges);

        return bridges;
    }
};
