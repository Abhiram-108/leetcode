class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> prefix(n+1, 0), res;
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        for (auto it : queries) {
            int i = upper_bound(nums.begin(), nums.end(), it) - nums.begin();

            long long left = 1LL * it * i - prefix[i];
            long long right = (prefix[n] - prefix[i]) - 1LL * it * (n - i);

            res.push_back(left + right);
        }
        return res;
    }
};
