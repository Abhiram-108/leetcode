class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        

        int m=matrix.size();
        int n=matrix[0].size();

        long long totalsum=0;
        int ct=0;
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                totalsum+=abs(matrix[i][j]);
                if(matrix[i][j]<0)
                ct++;
                mini=min(mini,abs(matrix[i][j]));
            }
        }
cout<<totalsum<<endl;
        if(ct % 2==0)
        return totalsum;
        cout<<mini;
        return totalsum-2*mini;
    }
};