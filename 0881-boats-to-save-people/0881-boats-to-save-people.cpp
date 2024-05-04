class Solution {
public:
    int numRescueBoats(vector<int>&a, int limit) {
        sort(a.begin(),a.end());
        int ct=0;
        int left=0;
        int right=a.size()-1;
        while(left<=right){
            if(a[left]+a[right]<=limit){
                left++;
            }
            right--;
            ct++;
        }
       return ct; 
    }
};