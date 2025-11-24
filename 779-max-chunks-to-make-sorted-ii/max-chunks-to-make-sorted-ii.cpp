class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n=arr.size(); 

        stack<int>st;

       
        for(int i=0;i<n;i++){
          int  ct=arr[i];
            while(st.size() && st.top() > arr[i]){
                ct=max(ct,st.top());
                st.pop();

            }

            st.push(ct);

        }

        cout<<st.size()<<endl;

        return st.size();


        
    }
};