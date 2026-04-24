class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalg = 0, totalc = 0;
        int curg = 0;
        int starting_point = 0;
        for (int i = 0; i < gas.size(); ++i) {
            totalg += gas[i];
            totalc += cost[i];
            curg += gas[i]-cost[i];
            if (curg < 0) {
                curg = 0;
                starting_point = i+1;
            }
        }
        return totalg >= totalc ? starting_point: -1;
    }
};

