class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxlength=0;
        int zeros=0;
        int length=0;
        while(r<nums.size()){
            if(nums[r]==0)
                zeros++;
            while(zeros>k ){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
                
            }
         
                length=r-l+1;
                maxlength=max(length,maxlength);
         
            r++;
        }
        return maxlength;
    }
};