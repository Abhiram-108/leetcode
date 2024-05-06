class Solution {
    private:
    int f(int i,int j,vector<vector<int>>&dp,string s1,string s2){
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=0+f(i-1,j-1,dp,s1,s2);
        return dp[i][j]=1+min(f(i-1,j,dp,s1,s2),min(f(i,j-1,dp,s1,s2),f(i-1,j-1,dp,s1,s2)));
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,word1,word2);
    }
};