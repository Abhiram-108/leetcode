class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        stack<int> st;
        vector<bool> visited(n, 0);

        queue<int>q;
        q.push(0);
        while(q.size()){
            int node=q.front();
            q.pop();
        visited[node] = 1;

            for(auto it:rooms[node]){
                if(!visited[it]){
                    // vis[it]=1;
                    q.push(it);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0)
            return false;
        }
        return true;
    }
};