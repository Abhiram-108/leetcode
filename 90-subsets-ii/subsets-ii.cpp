class Solution {
      void help(set<vector<int>>&s,vector<int>&nums,int index,vector<int>&temp){
        if(index==nums.size()){
            s.insert(temp);
            return;
        }
        help(s,nums,index+1,temp);

        temp.push_back(nums[index]);
        // int idx=index+1;
        // while(idx<nums.size() && nums[idx]==nums[idx-1]-1)
        // idx++;

        help(s,nums,index+1,temp);

        temp.pop_back();
        return;
        
            }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          int n=nums.size();
       vector<vector<int>>ans;
       vector<int>temp;
       set<vector<int>>s;

       sort(nums.begin(),nums.end());

       help(s,nums,0,temp); 
       for(auto it:s)
       ans.push_back(it);
       

       return ans;
        
    }
};