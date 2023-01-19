class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int n = (int)nums.size();
        int sum = 0;
        int rem = 0;
        mp[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += nums[i];
            rem = sum % k;
            if(rem < 0)
            {
                rem += k;
            }
            if(mp.find(rem) == mp.end())
            {
                mp[rem] = 1;
            }
            else
            {
                ans += mp[rem];
                mp[rem]++;
                
            }
        }
        return ans;
    }
};