class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1;
        int n = candies.size();
        int end = *max_element(candies.begin(), candies.end());
        int mid = 0;
        int ans = 0;
        long long count = 0;
        while(start <= end){
            count = 0;
            mid = start + (end - start) / 2;
            
            for(int i = 0; i < n; ++i){
                count += (long long)(candies[i] / mid);
            }
            if(count >= k){
                start = mid + 1;
                ans = max(ans, mid);
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};