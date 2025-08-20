class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> result;
        if (mat.empty()) return result;

        int srow = 0, scol = 0;
        int edrow = mat.size(), edcol = mat[0].size();

        while (srow < edrow && scol < edcol) {
            // Top row
            for (int i = scol; i < edcol; ++i) {
                result.push_back(mat[srow][i]);
            }
            srow++;

            // Right column
            for (int i = srow; i < edrow; ++i) {
                result.push_back(mat[i][edcol - 1]);
            }
            edcol--;

            // Bottom row
            if (srow < edrow) {
                for (int i = edcol - 1; i >= scol; --i) {
                    result.push_back(mat[edrow - 1][i]);
                }
                edrow--;
            }

            // Left column
            if (scol < edcol) {
                for (int i = edrow - 1; i >= srow; --i) {
                    result.push_back(mat[i][scol]);
                }
                scol++;
            }
        }

        return result;
    }
};