class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ans(n, 0);
        int ct = 1;
        int index = 0;

        while (candies > 0) {
            if (candies < ct) {
                ans[index] += candies;  // Add remaining candies only
                break;                  // All candies distributed
            } else {
                ans[index] += ct;
                candies -= ct;
                ct++;
                index = (index + 1) % n;
            }
        }

        return ans;
    }
};
