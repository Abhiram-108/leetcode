class Solution {
    private:
    void help(vector<vector<int>>&ans,vector<int>&nums,int index){
        if(index==nums.size()){
        ans.push_back(nums);
        return;}
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            help(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        help(ans,nums,0);
        return ans;
    }
};