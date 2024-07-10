class Solution {
    private:
    int solve(int index,vector<int>&nums,int ans){
        if(index>=nums.size())
            return ans;
        return solve(index+1,nums,ans^nums[index])+solve(index+1,nums,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        //sum of xor elements for every subset
        return solve(0,nums,0);
    }
};