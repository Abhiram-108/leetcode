class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // sort by end coordinate
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), cmp);
        
        int arrows = 1;
        int arrowPos = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > arrowPos) {
                arrows++;
                arrowPos = points[i][1];
            }
        }

        return arrows;
    }
};
