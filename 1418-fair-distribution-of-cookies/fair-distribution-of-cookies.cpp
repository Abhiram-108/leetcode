class Solution {

    int help(vector<int>& buckets, vector<int>& cookies, int limit, int idx) {
        if (idx == cookies.size()) 
            return 1;

        for (int i = 0; i < buckets.size(); i++) {

            if (buckets[i] + cookies[idx] <= limit) {

                buckets[i] += cookies[idx];

                if (help(buckets, cookies, limit, idx + 1)) 
                    return 1;

                buckets[i] -= cookies[idx];
            }

            if (buckets[i] == 0)
                break;
        }
        return 0;
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {

        int n = cookies.size();

        int l = 0, r = 0;
        for (int c : cookies) {
            l = max(l, c);
            r += c;
        }

        if (k >= n)
            return l;

        while (l < r) {
            int mid = (l + r) / 2;
            vector<int> buckets(k, 0);

            if (help(buckets, cookies, mid, 0)) {
                r = mid;          
            } 
            else {
                l = mid + 1;      
            }
        }
        return l;
    }
};
