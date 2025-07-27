class Solution {
public:
    vector<int> asteroidCollision(vector<int>&nums) {
        vector<int>a;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0)
            a.push_back(nums[i]);
            else{
                while(a.size() && a.back()>0 && a.back()<abs(nums[i]))
                a.pop_back();
                
                if(a.size() && a.back()==abs(nums[i]))
                a.pop_back();

                else if(!a.size() || a.back()<0)
                a.push_back(nums[i]);


                
            }
        }
        return a;

    }
};