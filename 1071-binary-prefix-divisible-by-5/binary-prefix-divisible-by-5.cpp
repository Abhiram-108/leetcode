class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int n = nums.size();
        vector<bool> res(n);

        int prefix = 0;  // only store modulo 5

        for(int i = 0; i < n; i++) {
            prefix = (prefix * 2 + nums[i]) % 5;
            res[i] = (prefix == 0);
        }

        return res;
    }
};
