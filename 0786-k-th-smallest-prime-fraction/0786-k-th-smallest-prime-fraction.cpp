class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        vector<float>ans;
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans.push_back((float)a[i]/(float)a[j]);
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ans[k-1]==(((float)a[i]/(float)a[j])))
                    return {a[i],a[j]};
            }
        }
        return {0,1};
        
    }
};