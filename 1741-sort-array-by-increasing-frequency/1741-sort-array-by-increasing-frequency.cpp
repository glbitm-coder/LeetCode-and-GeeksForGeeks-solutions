class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.second != b.second)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        
        unordered_map<int,int> mp;
        for(int i = 0; i < n; ++i){
            mp[nums[i]]++;
        }

        vector<pair<int,int>> vp;
        for(auto m: mp){
            vp.push_back({m.first,m.second});
        }

        sort(vp.begin(), vp.end(), cmp);

        vector<int> ans;
        for(auto it: vp){
            for(int i = 0; i < it.second; ++i){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};