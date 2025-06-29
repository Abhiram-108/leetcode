class Solution {
private:
int mod=1e9+7;
   

public:
    int numSubseq(vector<int>& a, int sum) {
        int n = a.size();
       sort(a.begin(),a.end());
       int l=0;
       int r=n-1;
       int ct=0;
       vector<int>p(n);
       p[0]=1;
       for(int i=1;i<n;i++){
        p[i]=(p[i-1]*2LL)%mod;
       }
       while(l<=r){
        if(a[l]+a[r]>sum){
            r--;
        }
        else{
            ct=(ct+p[r-l])%mod;
            l++;



        }
       }
       return ct;
    
    }
};
