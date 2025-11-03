class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            nums[i]=(2*nums[i])-1;
        }
        map<int,int>mp;
                mp[0] = -1;  // base case: prefix sum 0 before starting
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            // If this prefix sum was seen before, subarray between previous and current index is balanced
            if (mp.find(prefixSum) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum]);
            } else {
                mp[prefixSum] = i;  // store first occurrence of this sum
            }
        }

        return maxLen;

        
    }
};