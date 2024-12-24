class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); ++i){
            mp[s[i]] = i;
        }
        vector<int> ans;
        int start = 0, end = mp[s[0]];
        for(int i = start ; i < s.size() && end < s.size(); ++i){
            end = max(end, mp[s[i]]);
            if(i == end){
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};