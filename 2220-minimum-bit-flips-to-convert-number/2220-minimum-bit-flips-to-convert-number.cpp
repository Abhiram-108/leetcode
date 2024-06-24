class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result=start^goal;
        int count=0;
        while(result){
            if(result%2==1)
                count++;
            result/=2;
        }
        return count;
    }
};