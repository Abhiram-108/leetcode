class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]==target)
                ans.push_back(i);
        if(ans.size()==0)
            return {-1,-1};
        return {ans[0],ans[ans.size()-1]};
    }
};