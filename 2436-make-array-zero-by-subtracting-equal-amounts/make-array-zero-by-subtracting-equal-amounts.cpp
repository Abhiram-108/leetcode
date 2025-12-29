class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>s;
        for(auto it:nums){
            if(it!=0)
            s.insert(it);
        }

       cout<<s.size();
       return s.size();

        
    }
};