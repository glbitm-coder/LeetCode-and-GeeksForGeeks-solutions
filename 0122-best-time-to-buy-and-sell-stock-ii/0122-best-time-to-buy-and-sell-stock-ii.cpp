class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i = 0,j = 1, n = prices.size();
        int curr = prices[i], ans = 0;

        while(i < n && j < n){
            if(prices[j] < curr){
                ans = ans + (curr - prices[i] >= 0 ? curr - prices[i] : 0);
                i = j;
                curr = prices[j];

            }
            else{
                curr = prices[j];
            }
            ++j;
        }
        if(i < n){
            ans = ans + (curr - prices[i] >= 0 ? curr - prices[i] : 0);
        }
        return ans;
    }
};