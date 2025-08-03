class Solution {
    int help(vector<int>&nums,int k){
        map<int,int>mp;
        int r=0,l=0;
        int ct=0;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                mp.erase(nums[l]);
                l++;
            }
            
            ct+=r-l+1;
            r++;
        }
        return ct;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};