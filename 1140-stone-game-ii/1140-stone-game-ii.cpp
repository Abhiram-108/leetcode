class Solution {
    private:
    int f(vector<int>&p,int i,int m,vector<vector<int>>&dp){
        if(i>=p.size())
            return 0;
        if(dp[i][m]!=-1)
            return dp[i][m];
        int total=0;
        int ans=INT_MIN;
        for(int j=0;j<2*m;j++){
            if(i+j <p.size())
                total+=p[i+j];
            ans=max(ans,total-f(p,i+j+1,max(m,j+1),dp));
        }
        return dp[i][m]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>>dp(101,vector<int>(201,-1));
        int a=f(piles,0,1,dp);
        int sum=0;
        for(auto it:piles)
            sum+=it;
        return (sum+a)/2 ;
    }
};