class Solution {
public:
    vector<int> findMinHeightTrees(int v, vector<vector<int>>& edges) {
        if (v == 1) return {0};  // Single node tree case
        
        vector<int> adj[v];
        vector<int> indegree(v, 0);

        // Build the graph
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Calculate indegrees
        for (int i = 0; i < v; i++) {
            indegree[i] = adj[i].size();
        }

        queue<int> q;
        // Push all initial leaf nodes
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 1) q.push(i);
        }

        int remainingNodes = v;

        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;

            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (auto neighbor : adj[node]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
