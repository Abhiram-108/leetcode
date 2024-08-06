class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        vector<int>ans(26);
        for(auto it: word){
            ans[it-'a']++;
        }
        sort(ans.rbegin(),ans.rend());
        int count=0;
        for(int i=0;i<26;i++){
            count+=(i/8 +1)*ans[i];
        }
        return count;
     
        
        
    }
};