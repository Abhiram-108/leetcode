class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0;
        int totalcost=0;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalgas<totalcost)
        return -1;

        int index=0;
        int currcost=0;
        for(int i=0;i<n;i++){
             currcost+=gas[i]-cost[i];
            if(currcost<0){
                index=i+1;
                currcost=0;
            }
        }
        return index;

    }
};