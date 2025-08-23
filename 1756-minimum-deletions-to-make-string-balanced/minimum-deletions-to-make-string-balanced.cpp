class Solution {
public:
    int minimumDeletions(string s) {
  int deletions = 0, count_b = 0;
        for (char c : s) {
            if (c == 'b') {
                count_b++;
            } else { // c == 'a'
                deletions = min(deletions + 1, count_b);
            }
        }
        return deletions;
    }
};