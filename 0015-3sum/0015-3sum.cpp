class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum==0){
                    s.insert({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                }
                else if(sum<0)
                    start++;
                else
                    end--;
                
            }
        }
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
      
        
    }
};