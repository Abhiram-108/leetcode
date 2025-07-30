class Solution {
    private:
    int help(vector<vector<int>>&dp,int index,int jumps,vector<int>&nums){
        if(index>=nums.size()-1)
            return jumps;
        if(dp[index][jumps]!=-1)
            return dp[index][jumps];
        int mini=INT_MAX;
        for(int i=1;i<nums[index];i++){
            mini=min(mini,help(dp,index+i,jumps+1,nums));
        }
        return dp[index][jumps]=mini;
    }
public:
    int jump(vector<int>& nums) {
        // int index=0;
        // int jumps=0;
        // int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return help(dp,index,jumps,nums);
        int l=0;
        int r=0;
        int n=nums.size();
        int jumps=0;
        while(r<n-1){
            int farthest=0;

            for(int index=l;index<=r;index++){
                farthest=max(index+nums[index],farthest);
                

            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};