class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = 1;
            }
            else{
                mp[nums[i]] += 1;
                return true;
            }
        }
        return false;
    }
};