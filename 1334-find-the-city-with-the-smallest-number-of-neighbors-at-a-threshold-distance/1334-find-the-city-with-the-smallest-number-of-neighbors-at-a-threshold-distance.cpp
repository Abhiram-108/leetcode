class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        //given the graph is bidirectional
        for(auto it:edges){
            dis[it[0]][it[1]]=it[2];
            dis[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++)
            dis[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]==1e9 || dis[k][j]==1e9)
                        continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int cntcity=n;
        int cityno=-1;
        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++){
                if(dis[city][adjcity]<=distanceThreshold){
                    cnt++;
                }
                
            
            }
            if(cnt<=cntcity){
                cntcity=cnt;
                cityno=city;}
            
        }
        return cityno;
        
    }
};