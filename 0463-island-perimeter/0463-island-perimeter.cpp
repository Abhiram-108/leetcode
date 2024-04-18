class Solution {
public:
    int islandPerimeter(vector<vector<int>>&a) {
        int r=a.size();
        int c=a[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]==1){
                    ans+=4;
                if(i>0 && a[i-1][j]==1)
                    ans-=2;
                if(j>0 && a[i][j-1]==1)
                    ans-=2;
                }
            }
        }
        return ans;
        
    }
};