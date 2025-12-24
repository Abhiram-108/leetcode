class Solution {

    int help(int index,vector<vector<int>>&dp, int target,vector<int>&a){

        if(target==0)
        return 0;
        
        if(index==0){
            if(target % a[index] ==0)
            return target / a[index];


            return 1e9;
        }

        if(dp[index][target]!=-1)
        return dp[index][target];

        int nottake=0+help(index-1,dp,target,a);
        int take = 1e9;
if (a[index] <= target)
take=1+help(index,dp,target-a[index],a);

        return dp[index][target]=min(take,nottake);
     





    }
public:
    int numSquares(int n) {

      vector<int>a;
      for(int i=1;i<=n;i++){
        int temp=sqrt(i);
        if(temp * temp==i)
        a.push_back(i);
      }

      vector<vector<int>>dp(a.size(),vector<int>(n+1,-1));



      return help(a.size()-1,dp,n,a);


        
    }
};