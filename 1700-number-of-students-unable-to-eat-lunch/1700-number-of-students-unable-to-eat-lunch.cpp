class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
           int ones = 0, zeroes = 0;
        for(int i : students) {
            
            ones += i;
        }
        zeroes = students.size() - ones;
        
        for(int i = 0; i < sandwiches.size(); i++) {
            
            int val = sandwiches[i];
            if(val == 0) {
                
                if(zeroes == 0) {
                    
                    return sandwiches.size() - i;
                }
                zeroes--;
            } else {
                
                if(ones == 0) {
                    
                    return sandwiches.size() - i;
                }
                ones--;
            }
        }
        
        return 0;
    }
};