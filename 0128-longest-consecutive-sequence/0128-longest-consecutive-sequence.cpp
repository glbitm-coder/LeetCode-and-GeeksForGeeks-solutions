class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it:nums){
            s.insert(it);
        }

        int ans = 0;
        for(auto it:nums){
            if(s.find(it - 1) == s.end()){
                int start = it + 1;
                int count = 1;
                while(s.find(start) != s.end()){
                    ++count;
                    ++start;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};