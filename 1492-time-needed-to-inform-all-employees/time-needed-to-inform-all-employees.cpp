class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        }

        // BFS queue: {employeeID, totalTimeSoFar}
        queue<pair<int, int>> q;
        q.push({headID, 0});

        int totalTime = 0;

        while (!q.empty()) {
            auto [emp, currTime] = q.front();
            q.pop();

            totalTime = max(totalTime, currTime);

            // Inform all subordinates
            for (auto sub : adj[emp]) {
                q.push({sub, currTime + informTime[emp]});
            }
        }

        return totalTime;
    }
};
