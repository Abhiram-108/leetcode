class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n,1);
       long long temp=1;
       for(int i=0;i<n;i++){
        a[i]*=temp;
        temp*=nums[i];
       }
       temp=1;
       for(int i=n-1;i>=0;i--){
        a[i]*=temp;
        temp*=nums[i];
       }
       return a;

    }
};