class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const long long INF = 1e18;
        vector<long long> dist(n + 1, INF);  // Distance array
        vector<vector<pair<int, int>>> adj(n + 1);  // Adjacency list

        // Build adjacency list
        for (auto &it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
  // if (dis > dist[node]) continue;
           // skip outdated entries

            for (auto &it : adj[node]) {
                int nextNode = it.first;
                int weight = it.second;

                if (dis + weight < dist[nextNode]) {
                    dist[nextNode] = dis + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        long long maxi = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            maxi = max(maxi, dist[i]);
        }
        return (int)maxi;
    }
};
