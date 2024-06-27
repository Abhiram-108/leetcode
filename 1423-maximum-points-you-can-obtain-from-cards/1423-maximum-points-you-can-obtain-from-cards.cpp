class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int maxsum=0;
        int lsum=0,rsum=0;
        for(int i=0;i<k;i++){
            lsum+=card[i];
        }
        maxsum=lsum;
        int rightindex=card.size()-1;
        for(int i=k-1;i>=0;i--){
            rsum+=card[rightindex];
            lsum-=card[i];
            rightindex--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};