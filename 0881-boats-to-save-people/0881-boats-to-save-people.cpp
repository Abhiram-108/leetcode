class Solution {
public:
    int numRescueBoats(vector<int>&a, int limit) {
        sort(a.begin(),a.end());//sort the given people array
        int ct=0;
        int left=0;
        int right=a.size()-1;
        while(left<=right){
            if(a[left]+a[right]<=limit){ //if left person and right person are to be fitted in boat then we will increase left++ and right--;
                //else we will place right person only in boat
                left++;
            }
            right--;
            ct++;
        }
       return ct; 
    }
};