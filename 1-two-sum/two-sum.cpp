class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int>mp;
       int n=nums.size();
       for(int i=0;i<n;i++){
        if(mp.find(target-nums[i])==mp.end())
        mp[nums[i]]=i;
        else
        return {mp[target-nums[i]],i};
       } 
       return {-1,-1};
    }
};