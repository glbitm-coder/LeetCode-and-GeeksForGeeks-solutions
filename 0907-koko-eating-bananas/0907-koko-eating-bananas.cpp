class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int end = *max_element(piles.begin(), piles.end());
        int start = 1,mid = 0, ans = end;
        while(start <= end){
            mid = start + (end - start) / 2;
            long int minTime = 0;
            for(int i = 0; i < piles.size(); ++i){

                minTime += ceil((double)piles[i] / mid);
            }
            if(minTime <= h){
                end = mid - 1;
                ans = min(ans, mid);
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};