class Solution {
    int help(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        long long res = 0, sum = 0; // use long long here
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > k) {
                sum -= nums[l];
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
       if (k == 0) return help(nums, 0);  // No need to call with -1
    return help(nums, k) - help(nums, k - 1);
    }
};
