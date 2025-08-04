class Solution {
public:
    string longestPrefix(string s) {
        vector<int> p(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            int j = p[i - 1];
            if (s[i] == s[j]) {
                p[i] = j + 1;
                continue;
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = p[j - 1]; // \U0001f527 Fix: only this line changed
                }
                if (s[i] == s[j]) {
                    p[i] = j + 1;
                }
            }
        }
        int n = p[s.size() - 1];
        return s.substr(0, n);
    }
};
