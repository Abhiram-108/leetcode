class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxlength=0;
        int sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            if(r-l+1-sum>k){
                if(nums[l]==1){
                    sum-=nums[l];
                }
                l++;
            }
            maxlength=max(maxlength,r-l+1);
            r++;
        }
        return maxlength;
      
    }
};