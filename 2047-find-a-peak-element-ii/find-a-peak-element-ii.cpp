class Solution {
    int help_for_max(vector<vector<int>>& mat, int rows, int cols, int mid) {
        int index = -1;
        int maxi = INT_MIN;
        for (int i = 0; i < rows; i++) {
            if (mat[i][mid] > maxi) {
                maxi = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int l = 0, r = cols - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int row = help_for_max(mat, rows, cols, mid);

            int left  = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < cols) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid}; // found peak
            }
            else if (mat[row][mid] < left) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return {-1, -1}; // theoretically unreachable
    }
};
