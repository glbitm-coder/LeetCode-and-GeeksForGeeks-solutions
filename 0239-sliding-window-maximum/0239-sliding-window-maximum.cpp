class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        if(n <= k)
        {
            int p = *max_element(nums.begin(), nums.end());
            ans.push_back(p);
            return ans;
        }
        multiset<int, greater<int> > ms;
        for(int i = 0; i < k; ++i)
        {
            ms.insert(nums[i]);
        }
        ans.push_back(*(ms.begin()));
        for(int i = 1, j = k; j < n; ++i, ++j)
        {
            ms.erase(ms.find(nums[i - 1]));
            ms.insert(nums[j]);
            ans.push_back(*(ms.begin()));
        }
        return ans;
    }
};