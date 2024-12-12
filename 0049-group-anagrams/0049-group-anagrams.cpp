class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;

        for(auto it:strs)
        {
            vector<int> count(26, 0);
            string m = "";
            for(auto i:it){
                count[i - 'a']++;
            }
            for(auto i:count)
            {
                m += i;
            }
            mp[m].push_back(it);
        }
        
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};