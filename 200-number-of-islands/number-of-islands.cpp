class Solution {
    private:
    void dfs(int i,int j,vector<vector<char>>&a){
        if(i<0||i>=a.size() || j<0 ||j>=a[0].size()||a[i][j]=='0')
        return;
        a[i][j]='0';
        int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int r=i+dr[k];
            int c=j+dc[k];
            dfs(r,c,a);
        }
     
     return;
    }
public:
    int numIslands(vector<vector<char>>&a) {
       
       int m=a.size();
       int n=a[0].size();

int ct=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='1')
           ct++;
           dfs(i,j,a);
        }
       }
       return ct;


    }
};