class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;  // write pointer
        int read = 0;   // read pointer
        
        while (read < n) {
            char current = chars[read];
            int count = 0;
            
            // Count consecutive duplicates
            while (read < n && chars[read] == current) {
                read++;
                count++;
            }
            
            // Write character
            chars[write++] = current;
            
            // Write count (if more than 1)
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[write++] = c;
                }
            }
        }
        
        return write;
    }
};
