class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int i = 0; i< (int)costs.size(); ++i)
        {
            if(coins - costs[i] >= 0)
            {
                ans += 1;
                coins = coins - costs[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};