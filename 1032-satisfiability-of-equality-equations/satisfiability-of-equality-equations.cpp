class Solution {
    int find(int x,vector<int>parent){
        if(parent[x]!=x)
        parent[x]=find(parent[x],parent);
        return parent[x];

    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        for(int i=0;i<26;i++){
            parent[i]=i;

        }
        for(auto it:equations){
            if(it[1]=='='){
                int a=it[0]-'a';
                int b=it[3]-'a';
                int pa=find(a,parent);
                int pb=find(b,parent);
                if(pa!=pb){
                    parent[pa]=pb;
                }
            }
        }
        for(auto it:equations){
            if(it[1]=='!'){
                int a=it[0]-'a';
                int b=it[3]-'a';
                int pa=find(a,parent);
                int pb=find(b,parent);
                if(pa==pb)
                return 0;

            }
        }
        return 1;
    }
};