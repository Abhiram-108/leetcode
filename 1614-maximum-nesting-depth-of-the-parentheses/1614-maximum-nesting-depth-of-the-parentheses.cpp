class Solution {
public:
    int maxDepth(string s) {
        int result=0;
        stack<char>st;
       for(auto it:s){
           if(it=='(')
               st.push(it);
           else if(it==')')
               st.pop();
           result=max(result,(int)st.size());
       }
        return result;
    }
};