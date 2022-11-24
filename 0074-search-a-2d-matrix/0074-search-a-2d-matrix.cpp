class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int row = (int)matrix.size();
        int col = (int)matrix[0].size();
        int end = row * col - 1;
        int mid;
        while(start <= end){
            mid = (start + end) / 2;
            int number = matrix[mid / col][mid % col];
            if(target < number)
            {
                end = mid - 1;
            }
            else if(target > number)
            {
                start = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};