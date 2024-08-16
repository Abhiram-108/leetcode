class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
       int mini=a[0][0];
        int maxdist=0;
        int maxi=a[0].back();
        for(int i=1;i<a.size();i++){
            maxdist=max({maxdist,abs(a[i].back()-mini),abs(maxi-a[i][0])});
            mini=min(mini,a[i][0]);
            maxi=max(maxi,a[i].back());
        }
        return maxdist;
        
    }
};