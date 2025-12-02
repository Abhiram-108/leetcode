class Solution {

    vector<int>next_ge(vector<int>&nums){
        int n=nums.size();

        stack<int>st;
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
           
            while(st.size() && nums[st.top()]<=nums[i])
            st.pop();

            if(st.size()==0)
            nge[i]=n;
            else
            nge[i]=st.top();

            st.push(i);
        }

        return nge;

    }
    vector<int>prev_se(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(st.size() && nums[st.top()]>=nums[i])
            st.pop();
            if(st.size()==0)
            pse[i]=-1;

            else
            pse[i]=st.top();

            st.push(i);

        }
        return pse;
    }
public:
    bool increasingTriplet(vector<int>& nums) {
        
        vector<int>nge=next_ge(nums);
        vector<int>pse=prev_se(nums);
        int n=nums.size();

        for(int i=0;i<n;i++){
            if((pse[i]>=0 && nge[i]<n))
            return true;
        }

        return false;


    }
};