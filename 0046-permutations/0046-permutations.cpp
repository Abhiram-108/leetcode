class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>&ans,int pos){
        if(pos==nums.size()) ans.push_back(nums);
        for(int i=pos;i<nums.size();i++){
            swap(nums[pos],nums[i]);
            helper(nums,ans,pos+1);
            swap(nums[pos],nums[i]);
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,ans,0);
        return ans;
        
    }
};