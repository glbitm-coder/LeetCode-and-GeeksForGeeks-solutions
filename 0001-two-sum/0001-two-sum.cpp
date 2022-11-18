class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(mp.find(target - nums[i]) == mp.end())
            {
                mp[nums[i]] = i;
            }
            else{
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};