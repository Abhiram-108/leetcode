class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        vector<string>ans;
        for(int i=0;i<n;i++){

            string s=queries[i];
            int l=s.size();
            for(int j=0;j<m;j++){
                int ct=0;

                string word=dictionary[j];
                for(int k=0;k<l;k++){
                    if(s[k]!=word[k])
                        ct++;
                }
                if(ct<3){
                ans.push_back(queries[i]);
                    break;   
                }
                
            }
            
            
        }
        return ans;
    }
};