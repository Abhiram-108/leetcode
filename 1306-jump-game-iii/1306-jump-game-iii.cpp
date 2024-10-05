class Solution {
public:
    bool canReach(vector<int>& a, int start) {
        stack<int>st;
        st.push(start);
        vector<int>vis(a.size(),0);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(a[node]==0)
                return 1;
            if(!vis[node]){
                vis[node]=1;
                if(a[node]+node<a.size())
                    st.push(a[node]+node);
                if(node-a[node]>=0)
                    st.push(node-a[node]);
            }
        }
        return 0;
        
    }
};