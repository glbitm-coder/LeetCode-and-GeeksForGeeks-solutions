class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, n = gas.size(), ans = 0, curr = 0;
        for(int i = 0; i < n; ++i){
            curr += gas[i] - cost[i];
            totalTank += (gas[i] - cost[i]);
            if(curr < 0){
                ans = i + 1;
                curr = 0;
            }
        }
        if(totalTank < 0){
            return -1;
        }
        return ans;
    }
};