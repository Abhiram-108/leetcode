class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){
                st.push(s[i]);
            }
            else{
                if(s[i]==st.top()){
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        n=st.size();
        string s1="";
        while(n--){
            s1+=st.top();
            st.pop();
            
        }
        return s1;
        
    }
};