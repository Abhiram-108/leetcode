class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=26;
        vector<vector<int>>g(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            g[i][i]=0;
        }
        for(int i=0;i<cost.size();i++){
            int from=original[i]-'a';
            int to=changed[i]-'a';
            g[from][to]=min(g[from][to],cost[i]);
        }
        //optimised conversion paths
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                if(g[i][k]<1e9){
                    for(int j=0;j<n;j++){
                        if(g[k][j]<1e9){
                            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                        }
                    }
                }
            }
        }
        long long  totalcost=0;
        for(int i=0;i<source.length();i++){
            int sourcechar=source[i]-'a';
            int targetchar=target[i]-'a';
            if(sourcechar!=targetchar){
                if(g[sourcechar][targetchar]==1e9)
                    return -1;
                totalcost+=g[sourcechar][targetchar];
            }
        }
        return totalcost;
        
    }
};