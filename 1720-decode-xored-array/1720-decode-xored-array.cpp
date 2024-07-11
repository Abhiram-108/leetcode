class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        // int n=encoded.size()+1;
        vector<int>ans;
        int ele=first;
        ans.push_back(ele);
        for(int i=0;i<encoded.size();i++){
            ele=ele^encoded[i];
            ans.push_back(ele);
        }
        return ans;
        
        
    }
};