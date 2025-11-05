class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total=0,currs1=0,currs2=0,mxsub_sum=INT_MIN,mnsub_sum=INT_MAX;

        for(auto it:nums){
            total+=it;
            currs1+=it;
            currs2+=it;

            mxsub_sum=max(mxsub_sum,currs1);
            if(currs1<0)
            currs1=0;
            mnsub_sum=min(mnsub_sum,currs2);
            if(currs2>0)
            currs2=0;


        }

        if(total==mnsub_sum)
        return mxsub_sum;

        return max(total-mnsub_sum,mxsub_sum);
        
    }
};