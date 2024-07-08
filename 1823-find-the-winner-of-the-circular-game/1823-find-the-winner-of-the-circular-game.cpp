class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>circle;
        for(int i=1;i<=n;i++){
            circle.push_back(i);
        }
        int curr=0;
        while(circle.size()!=1){
            int next_index=(curr+k-1)%circle.size();
            circle.erase(circle.begin()+next_index);
            curr=next_index;
        }
        return circle[0];
    }
};