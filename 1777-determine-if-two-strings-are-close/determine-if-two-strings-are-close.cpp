class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> mp1, mp2;
        int m = word1.size(), n = word2.size();

        if (m != n)
            return false;

        for (char ch : word1) {
            mp1[ch]++;
        }

        for (char ch : word2) {
            mp2[ch]++;
            if (mp1.find(ch) == mp1.end())
                return false;  // if word2 has a char not in word1
        }

        // Compare the set of keys (characters)
        if (mp1.size() != mp2.size())
            return false;

        // Compare the frequency multisets
        multiset<int> freq1, freq2;
        for (auto [ch, count] : mp1) {
            freq1.insert(count);
        }
        for (auto [ch, count] : mp2) {
            freq2.insert(count);
        }

        return freq1 == freq2;
    }
};
