class Solution {
public:
    int stoneGameVI(vector<int>&A, vector<int>&B) {
        int n=A.size();
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={-A[i]-B[i],i};
        }
        sort(v.begin(),v.end());
        int f=1;
        int a=0,b=0;
        for(auto it:v){
            if(f==1) a+=A[it[1]];
            else b+=B[it[1]];
            f=1-f;
            
        }
        if(a>b) return 1;
        if(a==b) return 0;
        return -1;
    }
};