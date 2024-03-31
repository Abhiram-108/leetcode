class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n=a.size();
        // sort(a.begin(),a.end());
        // int v[100000]={0};
        // for(int i=0;i<n;i++){
        //     if(a[i]>=0){
        //         v[a[i]]=1;
        //     }
        // }
        // long long  x=a[n-1];
        // for(int i=1;i<x;i++){
        //     if(v[i]==0)
        //     return i;
        // }
        // return x+1;
        // vector<int>result;
        a.push_back(0);
        for(int i=0;i<n;i++){
            while( a[i]>=0 && a[i]<=n && a[i]!=a[a[i]])
            {
                swap(a[i],a[a[i]]);
            }
        }
    
    
        for( int  i=1;i<=n;i++){
            if(a[i]!=i)
            return i;
        }
        return n+1;
        
    }
};