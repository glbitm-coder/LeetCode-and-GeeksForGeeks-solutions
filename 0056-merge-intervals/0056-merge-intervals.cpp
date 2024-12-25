class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = 0;
        for(int i = 0; i < intervals.size(); ++i){
            n = ans.size();
            if(n == 0){
                ans.push_back(intervals[i]);
            }
            else{
                if(ans[n - 1][1] >= intervals[i][0]){
                    ans[n - 1][0] = min(intervals[i][0], ans[n - 1][0]);
                    ans[n - 1][1] = max(intervals[i][1], ans[n - 1][1]);
                }
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};