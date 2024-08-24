class Solution {
    private:
    int help(int s,int e,vector<vector<int>>&dp,vector<int>&v){
        if(s>e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int l=0,ans=0,r=0;
        for(int i=s;i<=e;i++)
            r+=v[i];
        for(int i=s;i<=e;i++){
            l+=v[i];
            r-=v[i];
            if(l<r) ans=max(ans,l+help(s,i,dp,v));
            if(l==r) ans=max(ans,r+max(help(s,i,dp,v),help(i+1,e,dp,v)));
            if(l>r) ans=max(ans,r+help(i+1,e,dp,v));
            
        }
        return dp[s][e]=ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        vector<vector<int>>dp(501,vector<int>(501,-1));
        return help(0,stoneValue.size()-1,dp,stoneValue);
    }
};