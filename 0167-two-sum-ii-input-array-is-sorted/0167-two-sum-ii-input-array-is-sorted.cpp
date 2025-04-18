class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(int i = 0, j = numbers.size() - 1; i < j; ){
            if(numbers[i] + numbers[j] > target){
                --j;
            }
            else if(numbers[i] + numbers[j] < target){
                ++i;
            }
            else{
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
        }
        return ans;
    }
};