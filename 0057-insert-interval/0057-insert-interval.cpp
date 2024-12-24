class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();
        bool newIntervalPushed = false;
        vector<vector<int>> ans;
        if(n > 0 && intervals[0][0] > newInterval[1]){
            ans.push_back(newInterval);
            newIntervalPushed = true;
        }
        while(i < n){
            if(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1]){
                if(i - 1 >= 0 && intervals[i - 1][1] < newInterval[0] && intervals[i][0] > newInterval[1]){
                    ans.push_back(newInterval);
                    newIntervalPushed = true;
                }
                ans.push_back(intervals[i]);
                ++i;
            }
            else{
                ans.push_back(newInterval);
                newIntervalPushed = true;
                int m = ans.size() - 1;
                while(i < n && !(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1])){
                    ans[m][0] = min(ans[m][0], intervals[i][0]);
                    ans[m][1] = max(ans[m][1], intervals[i][1]);
                    ++i;
                }
            } 
        }
        if(!newIntervalPushed){
            ans.push_back(newInterval);
        }
        return ans;
    }
};