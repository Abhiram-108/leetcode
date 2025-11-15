class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)
                q.push({i,j});
            }
        }

        while(q.size()){

            auto it=q.front();

            int r=it.first;
            int c=it.second;

            q.pop();

            for(int i=0;i<m;i++){
                matrix[i][c]=0;
            }

            for(int j=0;j<n;j++){
                matrix[r][j]=0;
            }
        }
        
    }
};