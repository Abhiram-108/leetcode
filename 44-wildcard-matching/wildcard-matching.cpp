class Solution {
    private:
     int help(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0 && j<0)
        return true;
        if(i<0 && j>=0)
        return false;
        if(j<0 && i>=0){
            for(int x=0;x<=i;x++){
                if(s1[x]!='*')
                return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        //match condition
        if(s1[i]==s2[j] || s1[i]=='?'){
        return dp[i][j]=help(i-1,j-1,s1,s2,dp);}
        if(s1[i]=='*'){
        return dp[i][j]=help(i-1,j,s1,s2,dp)|help(i,j-1,s1,s2,dp);}
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
         int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return help(n-1,m-1,p,s,dp);
    }
};