class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int r=grid[0].size()-1;
        
        int ct=0;

        for(int i=0;i<m;i++){
            while(  r>=0 && grid[i][r]<0) {
                ct+=m-i;
                r--;
            }
           
        }

        return ct;
    }
};