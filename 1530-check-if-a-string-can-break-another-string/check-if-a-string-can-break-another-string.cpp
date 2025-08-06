class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool s1_breaks_s2 = true;
        bool s2_breaks_s1 = true;

        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] < s2[i])
                s1_breaks_s2 = false;
            if (s2[i] < s1[i])
                s2_breaks_s1 = false;
        }

        return s1_breaks_s2 || s2_breaks_s1;
    }
};
