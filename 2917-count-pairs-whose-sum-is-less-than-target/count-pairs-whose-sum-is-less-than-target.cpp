class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ct=0;
        sort(nums.begin(),nums.end());
        while(l<r){
            if(nums[l]+nums[r]>=target)
            r--;
            else{
                ct+=(r-l);
                l++;
            }
        }
        cout<<ct<<endl;
        return ct;
        
    }
};