class Solution {
    private:
    int f(vector<vector<int>>&matrix,int row,int col){
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][col]>matrix[row][col])
                return 0;
        }
        return 1;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int mini=INT_MAX;
            int temp;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<mini)
                {
                    mini=matrix[i][j];
                    temp=j;
                }
            }
            if(f(matrix,i,temp))
                ans.push_back(matrix[i][temp]);
        }
        return ans;
    }
};