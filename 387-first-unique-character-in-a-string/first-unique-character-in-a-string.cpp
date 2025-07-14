class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vis(26, -1);  // Store index of first occurrence or -2 for repeated
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            if(vis[index] == -1)
                vis[index] = i;       // First time
            else
                vis[index] = -2;      // Repeated
        }

        int res = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(vis[i] >= 0)
                res = min(res, vis[i]);   // Track minimum valid index
        }

        return res == INT_MAX ? -1 : res;
    }
};
