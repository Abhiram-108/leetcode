class Solution {
public:
    void rotate(vector<vector<int>>&a) {
        int m=a.size();
        int n=a[0].size();
        vector<vector<int>>c=a;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[i][j]=c[n-1-j][i];
            }
        }
        
    }
};