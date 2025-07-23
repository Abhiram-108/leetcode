class Solution {
public:
    bool judgeSquareSum(int c) {
        long long x=sqrt(c);
        long long l=0;
        long long r=x;
        while(l<=r){
            long long sum=l*l+r*r;
            if(sum==c)
            return true;
            else if(sum<c)
            l++;
            else
            r--;
        }
        return false;
        
    }
};