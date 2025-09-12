class Solution {
public:
    vector<int> sumZero(int n) {
      vector<int>ans;
      int t=n/2;
      int l=-t;
      int r=t;
      while(t--){
        ans.push_back(l);
        ans.push_back(r);
        l++;
        r--;
      }
      if(n%2==1)
      ans.push_back(0);

      return ans;
      
    }
};