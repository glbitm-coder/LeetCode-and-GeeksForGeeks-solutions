class Solution {
public:
    bool static cmp(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if(k >= nums.size()) return nums;
        
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i)
        {
            mp[nums[i]]++;
        }
        
        vector<pair<int, int>> ordered;
        for(auto &it: mp)
        {
            ordered.push_back(it);
        }
        sort(ordered.begin(), ordered.end(), cmp);
        if( k >= mp.size())
        {
            for(auto &it:mp)
            {
                ans.push_back(it.first);
            }
        }
        else
        {
            for(int i = 0, j = 0; i < k; ++i, ++j)
            {
                ans.push_back(ordered[j].first);
            }
        }
        return ans;
    }
    
};