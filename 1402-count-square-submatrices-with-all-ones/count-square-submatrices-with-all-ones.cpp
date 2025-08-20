class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        ans[i][0]=matrix[i][0];
        for(int i=0;i<n;i++){
            ans[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]){
                    ans[i][j]=min(ans[i][j-1],min(ans[i-1][j],ans[i-1][j-1]))+1;
                }
                
            }
        }
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=ans[i][j];
            }
        }
        return sum;
        


    }
};