class Solution {
    int help(vector<vector<int>>&adj,vector<bool>&a,int child,int parent){
        int time=0;
        for(auto it:adj[child]){
            if(it==parent)
            continue;
            int x=help(adj,a,it,child);
            if(x || a[it]){
                time+=(x+2);
            }

        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // int n=edges.size();
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return help(adj,hasApple,0,-1);
    }
};