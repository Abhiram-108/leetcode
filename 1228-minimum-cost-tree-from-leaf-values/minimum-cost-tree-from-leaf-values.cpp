class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {

        stack<int>st;
        int ans=0;
        st.push(1e9);
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(st.size() && st.top()<=arr[i]){

                int el=st.top();
                st.pop();

                ans+=(el* min(st.top(),arr[i]));
                

            }
            st.push(arr[i]);
        }

        while(st.size()>2){
            int el=st.top();
            st.pop();
            ans+=(el*st.top());

        }

        return ans;
    
        
    }
};