class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r=0;
        int l=0;
        int minlen=1e9;
        int n=nums.size();
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                minlen=min(r-l+1,minlen);
                sum-=nums[l];
                l++;

            }
            r++;


        }
        if(minlen==1e9)
        return 0;
        return minlen;
    }
};