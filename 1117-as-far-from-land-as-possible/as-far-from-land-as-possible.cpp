class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // Push all land cells (multi-source BFS)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        // If no land OR all land → return -1
        if(q.empty() || q.size() == m*n)
            return -1;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        int distance = -1;   // IMPORTANT: start from -1

        while(!q.empty()) {
            int sz = q.size();
            distance++;      // increment BEFORE processing this layer

            while(sz--){
                auto [i, j] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int r = i + dr[k];
                    int c = j + dc[k];

                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 0){
                        grid[r][c] = 1;   // mark visited
                        q.push({r,c});
                    }
                }
            }
        }

        return distance;
    }
};
