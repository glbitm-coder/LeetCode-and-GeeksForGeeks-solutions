class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 0);
        ans[0] = 1;
        vector<int> temp;
        if(n > 0) temp.push_back(obstacles[0]);
        for(int i = 1; i < obstacles.size(); ++i){
            int idx = upper_bound(temp.begin(), temp.end(), obstacles[i]) - temp.begin();
            if(idx > temp.size() - 1)
            {
                temp.push_back(obstacles[i]);
                ans[i] = temp.size();
            }
            else
            { 
                temp[idx] = obstacles[i];
                ans[i] = idx + 1;
            }
        }
        return ans;
    }
};