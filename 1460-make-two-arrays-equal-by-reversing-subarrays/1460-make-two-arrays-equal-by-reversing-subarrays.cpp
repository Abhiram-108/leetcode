class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        if(target.size()!=arr.size())
            return false;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=target[i])
                return false;
            
        }
        return true;
    }
};