class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        for(auto it:s){
            int d=it-'A' + 1;
            res=res*26  + d;
        }

        return res;
        
    }
};