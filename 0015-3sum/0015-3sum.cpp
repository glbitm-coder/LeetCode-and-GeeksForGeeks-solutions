class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub_ans;
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n; ++i)
        {
            int start = i + 1;
            int end = n - 1;
            if(i > 0 and nums[i] == nums[i - 1])
            {
                continue;
            }
            while(start < end)
            {
                if(end < n - 1 and nums[end] == nums[end + 1])
                {
                    end--;
                    continue;
                }
                if(start > i + 1 and nums[start] == nums[start - 1])
                {
                    start++;
                    continue;
                }
                if(nums[i] + nums[end] + nums[start] == 0)
                {
                    
                    sub_ans.push_back(nums[i]);
                    sub_ans.push_back(nums[end]);
                    sub_ans.push_back(nums[start]);
                    ans.push_back(sub_ans);
                    sub_ans.clear();
                    start++;
                    end--;
                }
                else if(nums[i] + nums[end] + nums[start] > 0)
                {
                    end--;
                }
                else{
                    start++;
                }
                
            }
        }
        return ans;
    }
};