class Solution {
    private:
    void reverse(vector<int>&a,int left,int right){
        while(left<=right){
            long long  temp=a[left];
            a[left]=a[right];
            a[right]=temp;
            left++;
            right--;
        }
    }
    
    
public:
    void rotate(vector<int>& nums, int k) {
        
      int n=nums.size();
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
        
        
        
    }
};