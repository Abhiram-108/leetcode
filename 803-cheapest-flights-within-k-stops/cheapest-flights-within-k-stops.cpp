class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        q.push({0, {src, 0}}); // {stops, {node, cost}}

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stop > k) break;

            for (auto x : adj[node]) {
                int adjnode = x.first;
                int dist = x.second;

                if (cost + dist < dis[adjnode]) {
                    dis[adjnode] = cost + dist;
                    q.push({stop + 1, {adjnode, cost + dist}});
                }
            }
        }

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};
