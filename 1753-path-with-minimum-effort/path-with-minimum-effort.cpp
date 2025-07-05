class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});
        
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        dis[0][0] = 0;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row == m - 1 && col == n - 1)
                return diff;
            
            for (int i = 0; i < 4; i++) {
                int x = row + dr[i];
                int y = col + dc[i];
                
                if (x >= 0 && y >= 0 && x < m && y < n) {
                    int effort = abs(heights[x][y] - heights[row][col]);
                    int newEffort = max(effort, diff);
                    
                    if (newEffort < dis[x][y]) {
                        dis[x][y] = newEffort;
                        pq.push({newEffort, {x, y}});
                    }
                }
            }
        }
        
        return 0; // Should never reach here
    }
};
