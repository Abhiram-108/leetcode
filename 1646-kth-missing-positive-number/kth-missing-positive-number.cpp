class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n=arr.size();
        int l=0;
        int r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(arr[mid]-(mid+1)<k)
            l=mid+1;
            else
            r=mid;
        }
        return l+k;

    }
};