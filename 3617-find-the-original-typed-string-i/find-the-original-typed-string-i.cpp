class Solution {
public:
    int possibleStringCount(string word) {
        int ct = 1;
        int j = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                j++;
            } else {
                ct += (j - 1);
                j = 1;
            }
        }
        ct += (j - 1);  // ✅ Handle the last streak

        cout << ct << endl;
        return ct;
    }
};
