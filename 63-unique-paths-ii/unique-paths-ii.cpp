class Solution {
    int help(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp){
    if(i == 0 && j == 0)
    return a[0][0] == 0 ? 1 : 0;

        if(i<0 || j<0)
        return 0;
        if(a[i][j]==1)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int left=help(i,j-1,a,dp);
        int up=help(i-1,j,a,dp);

        return dp[i][j]=left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>&a) {
        
        int m=a.size();
        int n=a[0].size();
        if(m==1 && n==1 && a[0][0]==1)
        return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return help(m-1,n-1,a,dp);
    }
};