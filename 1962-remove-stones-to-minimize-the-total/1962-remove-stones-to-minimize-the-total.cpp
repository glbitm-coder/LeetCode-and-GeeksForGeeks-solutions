class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        multiset<int> s;
        int n = (int)piles.size();
        for(int i = 0; i < n; ++i)
        {
            s.insert(piles[i]);
        }
        for(int i = 0; i < k; ++i)
        {
            auto it = s.rbegin();
            int val = *it;
            s.erase(s.find(val));
           s.insert(val - val/2);
        
        }
        int ans = 0;
        for(auto it: s)
        {
            ans += it;
        }
        return ans;
    }
};