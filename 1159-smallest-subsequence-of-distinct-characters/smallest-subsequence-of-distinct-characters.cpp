class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int>f(26,0);
        vector<int>vis(26,0);
        for(auto it:s){
            f[it-'a']++;
        }

        stack<int>st;
        for(int i=0;i<s.size();i++){

            if(vis[s[i]-'a']){
                f[s[i]-'a']--;
                continue;
            }

            while(st.size() && st.top() > s[i]  && f[st.top()-'a']>0){
                vis[st.top()-'a']--;
                st.pop();
            }

            st.push(s[i]);
            f[s[i]-'a']--;
            vis[s[i]-'a']++;

        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
         
    }
};