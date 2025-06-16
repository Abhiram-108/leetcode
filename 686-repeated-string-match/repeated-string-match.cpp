class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int ct = 1; // Start with 1 because we've already added 'a' once.
        
        while (repeated.find(b) == string::npos) {
            repeated += a;  // Append 'a' to the string.
            ct++;
            
            // If the length of 'repeated' exceeds the length of 'b' + 'a', 
            // it's guaranteed that 'b' cannot fit in 'repeated'.
            if (repeated.size() > b.size() + a.size()) {
                break;
            }
        }
        
        // If 'b' was found, return the count. Otherwise, return -1.
        return repeated.find(b) == string::npos ? -1 : ct;
    }
};