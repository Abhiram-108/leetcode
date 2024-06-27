class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //its a 2 pointer technique and sliding window problem
        
        int l=0, r=0, len=0, maxlen=0;
        int hash[256];
        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }
        while (r < s.size()) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
            len = r - l + 1;
            maxlen = max(maxlen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};