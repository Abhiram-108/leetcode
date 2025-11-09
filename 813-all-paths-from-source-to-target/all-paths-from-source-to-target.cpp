class Solution {
    void dfs(int node,int dest,vector<vector<int>>&ans,vector<int>&path,vector<vector<int>>&adj,vector<int>&vis){
        if(node==dest){
            path.push_back(node);
            ans.push_back(path);
            return;
        }
        // vis[node]=1;
        path.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                // path.push_back(it);
                vis[it]=1;
                dfs(it,dest,ans,path,adj,vis);
                vis[it]=0;
            }
            // vis[it]=0;
           path.pop_back(); 
        }

    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        vector<int>path;
        vector<int>vis(n,0);
        dfs(0,n-1,ans,path,graph,vis);
        return ans;
    }
};