class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int max_freq_ele = nums[0];
        for(int i = 1 ; i < (int)nums.size(); ++i)
        {
            if(nums[i] == max_freq_ele)
            {
                count++;
            }
            else if(count == 0)
            {
                count++;
                max_freq_ele = nums[i];
            }
            else{
                count--;
            }
        }
        return max_freq_ele;
    }
};