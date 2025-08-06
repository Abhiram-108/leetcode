class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        int sum = 0;
        bool hasOdd = false;
        for (auto it : mp) {
            if (it.second % 2 == 0) {
                sum += it.second;
            } else {
                sum += it.second - 1; // use even part
                hasOdd = true;
            }
        }

        if (hasOdd) sum += 1; // add one odd character in the center
        return sum;
    }
};
