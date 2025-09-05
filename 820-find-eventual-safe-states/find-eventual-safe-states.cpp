class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>rev(n);
        vector<int>outdegree(n,0);

        for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
            for(auto it:graph[i]){
                rev[it].push_back(i);
            }
        }
        queue<int>q;
        set<int>s;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0)
            {
                q.push(i);
                s.insert(i);
            }
        }
        while(q.size()){
            int node=q.front();
            q.pop();
            for(auto  it:rev[node]){
                outdegree[it]--;
                if(outdegree[it]==0)
                {
                    q.push(it);
                    s.insert(it);
                }
            }
        }

        vector<int>ans(s.begin(),s.end());
        return ans;
    }
};