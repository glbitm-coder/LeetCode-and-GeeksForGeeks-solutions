class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        int count = 0;
        for(int i = 0, j = 0; j < nums.size(); ++j){
            if(s.find(nums[j]) != s.end()){
                continue;
            }
            else{
                nums[i] = nums[j];
                s.insert(nums[i]);
                ++count;
                ++i;
            }
        }
        return count;
    }
};