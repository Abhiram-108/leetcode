class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int cs=0;
        int l=0;
        int r=0;
        int maxlen=0;

       int sum=0;
       for(auto it:nums)
       sum+=it;

        x=sum-x;
        if(x==0)
        return n;

        while(r<n){
            cs+=nums[r];
            while(l<=r  && cs>x){
                cs-=nums[l];
                l++;
            }
            if(cs==x)
             maxlen=max(maxlen,r-l+1);
            r++;
        }

        if(maxlen==0)
        return -1;

        return n-maxlen;
       
    }
};