class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int a=x;
        int s;
        while(x){
            s+=x%10;
            x/=10;
        }
        if(a%s==0)
            return s;
        return -1;
        
    }
};