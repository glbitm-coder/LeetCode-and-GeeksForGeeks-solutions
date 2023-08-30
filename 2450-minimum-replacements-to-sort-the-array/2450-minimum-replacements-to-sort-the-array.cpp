class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long operations = 0, partitions = 0, upper_bound = nums[n - 1];
        for(int i = n - 2; i >= 0; --i){
            if(nums[i] > upper_bound){
                partitions = ceil((double)nums[i] / upper_bound);
                upper_bound = floor(nums[i] / partitions);
                operations += partitions - 1;
            } else {
                upper_bound = nums[i];
            }
        }
        return operations;
    }
};