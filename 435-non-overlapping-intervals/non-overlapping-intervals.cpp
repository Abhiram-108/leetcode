class Solution {

public:
bool static cmp(vector<int>s1,vector<int>s2){
    return s1[1]<s2[1];
}
    int eraseOverlapIntervals(vector<vector<int>>&a) {
        int n=a.size();
        sort(a.begin(),a.end(),cmp);
        int ct=1;
        int lasttime=a[0][1];
        for(int i=1;i<n;i++){
            if(lasttime<=a[i][0]){
                ct++;
                lasttime=a[i][1];
            }

        }
        return n-ct;
    }
};