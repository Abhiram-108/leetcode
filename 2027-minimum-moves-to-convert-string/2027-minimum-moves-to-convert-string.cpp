class Solution {
public:
    int minimumMoves(string s) {
        int sum = 0;
        int sz = s.size();
        for(int i = 0 ; i <sz ; i++) {
            while(i<sz && s[i]=='X') {sum++, i+=3;}
        }
        return sum;
    }
};