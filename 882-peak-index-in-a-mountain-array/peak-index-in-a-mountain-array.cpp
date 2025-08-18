class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n=a.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(l==r)
            return r;
            if(a[mid]>a[mid+1])
            r=mid;
            else
            l=mid+1;
        }
        return l;
    }
};