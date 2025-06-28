class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        // Push all 0s as source points for multi-source BFS
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col] = steps;

            for(int i = 0; i < 4; i++) {
                int mrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(mrow >= 0 && mrow < m && ncol >= 0 && ncol < n && vis[mrow][ncol] == 0) {
                    vis[mrow][ncol] = 1;
                    q.push({{mrow, ncol}, steps + 1});
                }
            }
        }

        return dis;
    }
};
