class Solution {
    int help(vector<int>&dp,vector<int>&nums,int index){
        if(index==0)
            return nums[index];
        if(index<0)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int take=nums[index]+help(dp,nums,index-2);
        int nottake=0+help(dp,nums,index-1);
        return dp[index]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return help(dp,nums,nums.size()-1);
        
    }
};