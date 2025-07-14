class Solution {
    void dfs(int index,vector<int>&vis,vector<vector<int>>&adj){
        vis[index]=1;
        for(auto it:adj[index]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }
        int ct=0;
        vector<int>vis(n,0);
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    ct++;
                    dfs(i,vis,adj);
                }

            }
            return ct;

    }
};