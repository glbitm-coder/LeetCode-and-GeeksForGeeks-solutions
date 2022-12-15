class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        int n = (int)intervals.size();
        for(int i = 0 ; i < n; ++i)
        {
            if(ans.empty())
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                vector<int> temp = ans[ans.size() - 1];
                
                if(temp[1] >= intervals[i][0] )
                {
                    ans[ans.size() - 1][0] = min(ans[ans.size() - 1][0], intervals[i][0]);
                    ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
                }
                else
                {
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
        
    }
};