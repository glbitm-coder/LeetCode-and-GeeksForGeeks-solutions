class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) 
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int n = (int)points.size();
        int prev = points[0][1];
        int ans = 1;
        for(int i = 1 ; i < n; ++i)
        {
            if(prev >= points[i][0])
            {
                continue;
            }
            else{
                ++ans;
                prev = points[i][1];
            }
        }
        return ans;
    }
};