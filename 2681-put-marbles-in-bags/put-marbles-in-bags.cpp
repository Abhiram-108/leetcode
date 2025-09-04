class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> a;
        
        for (int i = 1; i < n; i++) {
            a.push_back((long long)weights[i - 1] + weights[i]);
        }

        sort(a.begin(), a.end());

        long long mini = 0, maxi = 0;
        for (int i = 0; i < k - 1; i++) {
            mini += a[i];
            maxi += a[a.size() - 1 - i];
        }

        return maxi - mini;
    }
};
