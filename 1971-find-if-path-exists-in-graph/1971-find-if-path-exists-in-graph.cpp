class Solution {
    private:
    int bfs(vector<int>vis,unordered_map<int,list<int>>adj,int src,int des){
        int flag=0;
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto  it: adj[x]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
                if(it==des){
                    flag=1;
                    break;
                }
            }
        }
        return flag;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)
            return 1;
       unordered_map<int,list<int>> adj;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        return bfs(vis,adj,source,destination);
        
    }
};