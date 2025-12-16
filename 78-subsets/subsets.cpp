class Solution {
    void help(vector<vector<int>>&ans,vector<int>&nums,int index,vector<int>&temp){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        help(ans,nums,index+1,temp);

        temp.push_back(nums[index]);

        help(ans,nums,index+1,temp);

        temp.pop_back();
        return;
        
            }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>>ans;
       vector<int>temp;
       help(ans,nums,0,temp); 

       return ans;
    }
};