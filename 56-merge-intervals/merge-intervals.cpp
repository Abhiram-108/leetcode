class Solution {
    bool static cmp(vector<int>&a1,vector<int>&a2){
    return a1[0]<a2[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>&a) {
        sort(a.begin(),a.end(),cmp);
        vector<vector<int>>ans;
        auto start=a[0];
        for(int i=1;i<a.size();i++){
            if(start[1]>=a[i][0]){
                start[1]=max(a[i][1],start[1]);
            }
            else{
                ans.push_back(start);
                start=a[i];
            }
        }
        ans.push_back(start);
        return ans;
    }
};