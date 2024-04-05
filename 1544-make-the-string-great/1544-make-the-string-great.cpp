class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.size()==0)
                st.push(s[i]);
            else if(st.top()==s[i]-32 || st.top()==s[i]+32)
                st.pop();
            else 
                st.push(s[i]);
        }
        string ans;
        n=st.size();
        while(n--){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
       
        
    }
};