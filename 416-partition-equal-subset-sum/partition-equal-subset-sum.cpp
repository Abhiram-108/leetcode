class Solution {
    int help(vector<int>&nums,vector<vector<int>>&dp,int index,int target){
        if(index==0){
            if(nums[index]==target)
            return 1;
            return 0;
        }
        if(target==0)
        return 1;

        if(dp[index][target]!=-1)
        return dp[index][target];

        int nottake=help(nums,dp,index-1,target);
        int take=0;
        if(nums[index]<=target)
        take=help(nums,dp,index-1,target-nums[index]);

        return dp[index][target]=nottake|take;
    }
public:
    bool canPartition(vector<int>& nums) {
       int sum=0;

       int n=nums.size();

       for(auto it:nums)
       sum+=it;

       if(sum & 1 ==1)
       return 0;

       int target=sum/2;

       vector<vector<int>>dp(n,vector<int>(target+1,-1));

       return help(nums,dp,n-1,target);
    }
};