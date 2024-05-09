class Solution {
public:
    long long maximumHappinessSum(vector<int>&a, int k) {
        sort(a.begin(),a.end(),greater<int>());
          int i = 0;
        long long res = 0;

        while(k--) {
            a[i] = max(a[i] - i, 0);
            res += a[i++];
        }

        return res;
        
    }
};