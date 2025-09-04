class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int mini=1e9;
        for(int i=1;i<nums.size();i++){
            mini=min(abs(nums[i]-nums[i-1]),mini);
        }
        return mini;
    }
};