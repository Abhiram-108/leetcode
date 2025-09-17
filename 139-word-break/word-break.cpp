class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int maxLen = 0;
        for (auto &word : wordDict) {
            maxLen = max(maxLen, (int)word.size());
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1; // empty string is always breakable

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= max(0, i - maxLen); j--) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = 1;
                    break; // found a valid break, no need to check more
                }
            }
        }

        return dp[n];
    }
};
