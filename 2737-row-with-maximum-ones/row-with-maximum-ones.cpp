class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
        int sum=0;
        int index=0;

        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            int temp=0;
            for(auto it:matrix[i])
            temp+=it;
            if(sum<temp)
            {
                sum=temp;
                index=i;
            }
        }


        return {index,sum};
        
 
    }
};