class Solution {
    private:
    void dfs(vector<vector<char>>&a,int i,int j){
        if(i<0 || i>=a.size() ||j<0 || j>=a[0].size() ||a[i][j]=='0')
            return;
        else
        {
            a[i][j]='0';
            dfs(a,i-1,j);
            dfs(a,i+1,j);
            dfs(a,i,j-1);
            dfs(a,i,j+1);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>&a) {
        int m=a.size();
        int n=a[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='1')
                {
                    count++;
                    dfs(a,i,j);
                }
            }
        }
        return count;
        
    }
};