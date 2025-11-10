class Solution {
     map<int,int>parent;
     
     int find(int x){
        if(parent.find(x)==parent.end())
        return parent[x]=x;

        return parent[x]==x ? x:find(parent[x]);
     }
  

public:
    int removeStones(vector<vector<int>>& stones) {
       int n=stones.size();

       for(auto it:stones){
        int first=it[0];
        int second=~it[1];

        int pa=find(first);
        int pb=find(second);

        if(pa!=pb)
        parent[pb]=pa;
       }

       set<int>st;
       for(auto it:stones){
        st.insert(find(parent[~it[1]]));
       }

       return stones.size()-st.size();
      
       


    }
};
