class Solution {
    int help(vector<int>&nums,int k){
         int l=0;
        int r=0;
        int n=nums.size();
        int sum=0;
        int ct=0;
        while(r<n){
            sum+=(nums[r]%2);
            
            while(sum>k){

                sum=sum-(nums[l] % 2);
                l++;

            }
            if(sum<=k)
            ct=ct+(r-l+1);
            r++;
        }
        return ct;

    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       
        return help(nums,k)-help(nums,k-1);
    }
};