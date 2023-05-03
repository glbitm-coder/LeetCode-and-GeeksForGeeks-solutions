class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
         unordered_set<int> s1, s2;
        vector<vector<int>> ans;
        vector<int> sub_ans_1;
        vector<int> sub_ans_2;
        for(int i = 0; i < nums1.size(); ++i)
        {
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); ++i)
        {
            s2.insert(nums2[i]);
        }
        for(auto it:s1)
        {
            if(s2.find(it) == s2.end())
            {
                sub_ans_1.push_back(it);
            }
        }
        for(auto it:s2)
        {
            if(s1.find(it) == s1.end())
            {
                sub_ans_2.push_back(it);
            }
        }
        ans.push_back(sub_ans_1);
        ans.push_back(sub_ans_2);
        return ans;
    }
};