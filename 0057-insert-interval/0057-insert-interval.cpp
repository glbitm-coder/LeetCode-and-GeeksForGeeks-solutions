class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool isinserted = false;
        int n = (int)intervals.size();
        for(int i = 0; i < n; ++i)
        {
            if(intervals[i][0] > newInterval[1] && intervals[i][0] > newInterval[0])
            {
                auto it = intervals.begin() + i;
                intervals.insert(it, newInterval);
                isinserted = true;
                return intervals;
            }
            if(intervals[i][1] >= newInterval[0])
            {
                int j = i;
                auto start = intervals.begin() + i;
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                ++i;
                auto end = intervals.begin() + i;
                while(i < n && intervals[i][0] <= newInterval[1])
                {
                     ++i;
                    end = intervals.begin() + i;
                }
                newInterval[1] = max(intervals[i - 1][1], newInterval[1]);
                intervals.erase(start, end);
                
                intervals.insert(intervals.begin() + j, newInterval);
                isinserted = true;
                return intervals;
            }
            
        }
        if(isinserted == false)
        {
            intervals.push_back(newInterval);
        }
        return intervals;
    }
};