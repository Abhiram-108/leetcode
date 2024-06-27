class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]!=mat[i-1][j-1])
                    return 0;
            }
        }
        return 1;
        
        
    }
};