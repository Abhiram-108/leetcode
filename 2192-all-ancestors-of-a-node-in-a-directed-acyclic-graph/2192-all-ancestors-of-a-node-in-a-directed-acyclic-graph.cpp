class Solution {
    private:
    void dfs(int node,vector<vector<int>>&v,vector<bool>&vis){
        vis[node]=true;
        for(int i=0;i<v[node].size();i++){
            if(vis[v[node][i]])
                continue;
            dfs(v[node][i],v,vis);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       vector<vector<int>>ans(n),v(n);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            dfs(i,v,vis);
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                if(vis[j])
                    ans[j].push_back(i);
            }
        }
        return ans;
    }
};