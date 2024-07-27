class Solution {
public:
    string frequencySort(string s) {
         map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }

        vector<pair<int, char>> v;
        for (auto it : m) {
            v.push_back({it.second, it.first});
        }

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        string result = "";
        for (auto it : v) {

            for (int i = 0; i < it.first; i++) {
                result += it.second;
            }
        }
        return result;
    }
};
