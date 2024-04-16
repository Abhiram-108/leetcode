class Solution {
public:
   static bool cmp(vector<int>a,vector<int>b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>&a, int wt) {
        sort(a.begin(),a.end(),cmp);
        int ans=0;
        int i=0;
        while(wt>0 && i<a.size()){
            if(wt>a[i][0]){
                wt-=a[i][0];
                ans+=a[i][0]*a[i][1];
            }
            else{
                ans+=wt*a[i][1];
                wt=0;
                
            }
            i++;
        }
        return ans;
        
        
    }
};