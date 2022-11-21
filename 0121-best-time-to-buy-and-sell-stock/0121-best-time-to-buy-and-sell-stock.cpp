class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int ans = 0;
        if(n == 0 || n == 1)
        {
            return ans;
        }
        
        int max_val = prices[n- 1];
        for(int i = n  - 2; i >= 0; --i)
        {
            if(prices[i] > max_val)
            {
                max_val = prices[i];
            }
            else{
                ans = max(ans, max_val - prices[i]);
            }
        }
        return ans;
    }
};