class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = (int)temperatures.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i)
        {
            mp[temperatures[i]] = 0;
        }
        vector<int> ans(n, - 1);
        int max = *max_element(temperatures.begin(), temperatures.end());
        for(int i = 0; i < n; ++i)
        {
            if(temperatures[i] == max)
            {
                ans[i] = 0;
                mp[temperatures[i]] = 0;
            }
        }
        ans[n - 1] = 0;
        mp[temperatures[n-1]] = 0;
        for(int i = n-1; i >=0 ; --i)
        {
            int count = 0;
            while(!s.empty() && temperatures[i] >= s.top())
            {
                count += mp[s.top()];
                s.pop();
            }
            if(s.empty())
            {
                count = 0;
                mp[temperatures[i]] = 0;
            }
            else
            {
                count += 1;
            }
           
            s.push(temperatures[i]);
            if(ans[i] == 0)
            {
                continue;
            }
             mp[temperatures[i]] = count;
             ans[i] = count;
        }
        return ans;
    }
};