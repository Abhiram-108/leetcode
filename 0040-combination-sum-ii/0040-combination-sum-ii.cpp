class Solution {
    private:
    void find_combinations(int index,vector<int>&combinations,vector<int>ds,vector<vector<int>>&ans,int target){
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<combinations.size();i++){
            if(i>index && combinations[i]==combinations[i-1])
                continue;
            if(combinations[i]>target)
                break;
            ds.push_back(combinations[i]);
            find_combinations(i+1,combinations,ds,ans,target-combinations[i]);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        find_combinations(0,candidates,ds,ans,target);
        return ans;
        
        
    }
};