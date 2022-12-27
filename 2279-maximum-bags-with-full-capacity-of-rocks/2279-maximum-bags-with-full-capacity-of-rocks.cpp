class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = (int)rocks.size();
        for(int i = 0; i < n; ++i)
        {
            rocks[i] = capacity[i] - rocks[i];
        }
        sort(rocks.begin(), rocks.end());
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(rocks[i] == 0)
            {
                ++ans;
            }
            else if(rocks[i] <= additionalRocks)
            {
                ++ans;
                additionalRocks = additionalRocks - rocks[i];
            }
        }
        return ans;
    }
};