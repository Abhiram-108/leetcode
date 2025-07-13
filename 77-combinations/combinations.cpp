class Solution {
 
    void help(vector<vector<int>>&ans,int n,int k,int index,   vector<int>&temp){
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<=n;i++){
            temp.push_back(i);
            help(ans,n,k,i+1,temp);
            temp.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        //this can be achived by recursion+backracking
   vector<int>temp;
        vector<vector<int>>ans;
        help(ans,n,k,1,temp);
        return ans;
    }
};