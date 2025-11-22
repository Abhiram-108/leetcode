class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sub=0,add=0;
        for(auto it:nums){
            int rem= it%3;
            if(rem==1)
            sub++;
            if(rem==2)
            add++;
        }

        return add+sub;
        
    }
};