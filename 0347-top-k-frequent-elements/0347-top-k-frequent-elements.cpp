class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;

        unordered_map<int,int> mp;
        int maxnum = nums[0];
        for(int i = 0; i < nums.size(); ++i)
        {
            ++mp[nums[i]];
            maxnum = max(maxnum, mp[nums[i]]);
        }
        vector<vector<int>> v(maxnum + 1, vector<int> (0,0));
        for(auto it:mp){
            v[it.second].push_back(it.first);
        }
        
        for(int i = maxnum; i >= 0; --i)
        {
            if(v[i].size() > 0 && k > 0){
                for(auto it:v[i]){
                    if(k > 0)
                        {
                            ans.push_back(it);
                            --k;
                        }
                }
            }
        }
        return ans;
    }
};