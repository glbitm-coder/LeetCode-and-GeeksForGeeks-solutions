class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> s;
        for(int i = 0; i < trust.size(); ++i)
        {
            s.insert(trust[i][0]);
        }
        for(int i = 1; i <= n; ++i)
        {
            int count = 0;
            for(int j = 0; j < trust.size(); ++j)
            {
                if(trust[j][1] == i)
                {
                    count++;
                }
            }
            if(count == n - 1 && s.find(i) == s.end())
            {
                return i;
            }
        }
        return -1;
    }
};