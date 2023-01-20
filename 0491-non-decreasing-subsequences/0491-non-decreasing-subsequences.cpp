class Solution {
public:
    void static backtrack(int curr_index, vector<int>& nums, vector<int>& sub_ans, set<vector<int>>& result)
    {
        if(curr_index == nums.size())
        {
            if(sub_ans.size() >= 2)
            {
                result.insert(sub_ans);

            }
            return ;
        }
        if(sub_ans.empty() || sub_ans.back() <= nums[curr_index])
        {
            sub_ans.push_back(nums[curr_index]);
            backtrack(curr_index+1, nums, sub_ans, result);
            sub_ans.pop_back();
        }
        backtrack(curr_index+1, nums, sub_ans, result);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> sub_ans;
        set<vector<int>>result;
        backtrack(0, nums,sub_ans, result);
       return  vector(result.begin(), result.end());
    }
};