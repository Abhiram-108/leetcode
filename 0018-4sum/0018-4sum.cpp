class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>s;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long  dump=(long long)target-(long long)nums[i]-(long long)nums[j];
                int start=j+1;
                int end=n-1;
                while(start<end){
                    int sum=nums[start]+nums[end];
                    if(sum==dump){
                        s.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                    else if(sum<dump)
                        start++;
                    else
                        end--;
                }
                
            }
        }
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};