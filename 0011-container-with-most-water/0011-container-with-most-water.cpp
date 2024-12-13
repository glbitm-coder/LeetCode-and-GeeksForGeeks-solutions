class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        

        int i = 0, j = n - 1;
        while(i < j){
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if(height[i] > height[j]){
                --j;
            }
            else if(height[i] < height[j]){
                ++i;
            }
            else{
                ++i;
                --j;
            }
        }
        return ans;
    }
};