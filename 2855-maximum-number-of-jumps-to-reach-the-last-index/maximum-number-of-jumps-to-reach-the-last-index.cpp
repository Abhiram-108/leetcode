class Solution {
    int help(int index, int n, int target, vector<int>&nums,vector<int>&dp){
        if(index==n-1)
        return 0;

        if(dp[index]!=-1)
        return dp[index];
        int ans=INT_MIN;

        for(int i=index+1;i<n;i++){
            if(abs(nums[i]-nums[index])<=target)
            ans=max(ans,1+help(i,n,target,nums,dp));
        }
        return  dp[index]=ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int>dp(n,-1);
        int ans=help(0,n,target,nums,dp);




        if(ans<0)
        return -1;

        return ans;
    }
};