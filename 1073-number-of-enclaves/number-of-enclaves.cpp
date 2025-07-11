// This is still not a recommended approach for enclaves but fixed logically for learning
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Push all land cells on the boundary into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        // BFS to mark all land connected to boundary
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            for (int k = 0; k < 4; ++k) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    !vis[ni][nj] && grid[ni][nj] == 1) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }

        // Count unvisited land cells
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1 && !vis[i][j])
                    count++;

        return count;
    }
};
