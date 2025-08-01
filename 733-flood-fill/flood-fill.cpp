class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        int originalColor = image[sr][sc];
        if (originalColor == color) return image; // No change needed

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int r = x + dr[i];
                int c = y + dc[i];

                // Check bounds and same original color
                if (r >= 0 && r < m && c >= 0 && c < n && image[r][c] == originalColor) {
                    image[r][c] = color;
                    q.push({r, c});
                }
            }
        }

        return image;
    }
};
