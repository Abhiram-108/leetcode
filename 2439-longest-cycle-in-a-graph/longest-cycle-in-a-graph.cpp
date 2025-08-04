class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<int>& extra, vector<int>& dist_node, vector<int>& edges, int distance, int &ans) {
        // if (node == -1) return; // Fix: If there's no outgoing edge, stop the DFS

        if (!vis[node]) {
            vis[node] = 1;
            extra[node] = 1;
            dist_node[node] = distance;
            
            if (edges[node] != -1) { // Fix: Prevent invalid access
                dfs(edges[node], vis, extra, dist_node, edges, distance + 1, ans);
            }
        } else {
            if (extra[node]) { // If the node is visited within the current path, it's a cycle
                ans = max(ans, distance - dist_node[node]);
            }
        }
        extra[node] = 0; // Mark the node as processed
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> dist_node(n, 0);
        vector<int> vis(n, 0);
        vector<int> extra(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, extra, dist_node, edges, 0, ans);
            }
        }

        return ans;
        // int n=edges.size();
        // vector<int>vis(n,0);
        // int longest=-1;
        // for(int i=0;i<n;i++){
        //     if(vis[i])
        //     continue;
        //     map<int,int>mp;
        //     int step=0;
        //     int current=i;
        //     while(current!=-1){
        //         if(mp.count(current)){
        //             longest=max(longest,step-mp[current]);
        //             break;
        //         }
        //         if(vis[current])
        //         break;
        //         mp[current]=step;
        //         step++;
        //         vis[current]=1;
        //         current=edges[current];
        //     }

        // }
        // return longest;
    }
};
