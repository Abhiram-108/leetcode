class Solution {
    long long ans = 0; // To store total fuel cost

    int dfs(int node, int parent, vector<vector<int>>& adj, int seats) {
        int people = 1; // Each node has 1 person (including current node)

        for (auto child : adj[node]) {
            if (child == parent) continue; // Avoid going back to parent

            int subtree_people = dfs(child, node, adj, seats);

            // Number of cars needed = ceil(subtree_people / seats)
            ans += (subtree_people + seats - 1) / seats;
            people += subtree_people;
        }
        return people;
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1; // Number of cities
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto &it : roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // Undirected roads
        }

        dfs(0, -1, adj, seats); // Start from capital (0)
        return ans;
    }
};
