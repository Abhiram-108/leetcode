class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=x^y;
        int ct=0;
        while(res){
            res=res & (res-1);
            ct++;
        }
        return ct;

    }
};