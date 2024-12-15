class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        int start = 0, end = n * m - 1, mid = 0, num = 0;

        while(start <= end){
            mid = start + (end - start) / 2;
            num = matrix[mid/n][mid%n];
            if(num == target){
                return true;
            }
            else if(target > num){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }
};