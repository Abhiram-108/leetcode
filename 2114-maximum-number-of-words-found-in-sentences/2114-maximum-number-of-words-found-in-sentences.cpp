class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string s=sentences[i];
            int count=0;
            for(int j=0;j<s.size();j++){
                if(s[j]==' '){
                    count++;
                    ans=max(count,ans);
                }
                
            }
        }
        ans++;
        return ans;
        
    }
};