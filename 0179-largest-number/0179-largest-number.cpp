class Solution {
    bool static compare(int a,int b){
        string x=to_string(a);
        string y=to_string(b);
        if((x+y)>(y+x))
            return true;
        else
            return false;
    }
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),compare);
        
        if(nums[0]==0)
            return "0";
    
        string ans="";
        for(auto it:nums){
            ans+=to_string(it);
        }
        return ans;
        
    }
};