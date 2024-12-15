class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<pair<int,int>> st;
        for(int i = 0; i < n; ++i){
            if(st.empty()){
                st.push({heights[i], i});
            }
            else{
                int val = i;
                while(!st.empty() && st.top().first > heights[i]){
                    val = st.top().second;
                    ans = max(ans, st.top().first * (i - st.top().second));
                    st.pop();
                }
                st.push({heights[i], val});
            }
        }
        while(!st.empty()){
            ans = max(ans, st.top().first * (n - st.top().second));
            st.pop();
        }
        return ans;
    }
};