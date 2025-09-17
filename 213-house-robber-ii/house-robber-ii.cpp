class Solution {
    private:
    int help(vector<int>&nums,vector<int>&dp,int index,int base){
        if(index==base)
            return dp[index]=nums[index];
        if(index<base)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        int take=nums[index]+help(nums,dp,index-2,base);
        int nottake=0+help(nums,dp,index-1,base);
        return dp[index]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<int> dp1(n, -1);
        int withoutLast = help(nums,dp1, n-2, 0);
        
        vector<int> dp2(n, -1);
        int withoutFirst = help(nums, dp2,n-1, 1);
        
        return max(withoutLast, withoutFirst);
        
        
    }
};