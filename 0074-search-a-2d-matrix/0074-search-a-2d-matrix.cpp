class Solution {
public:
    bool binary(vector<vector<int>>& matrix, int a, int target)
    {
        int start = 0; 
        int end = (int)matrix[0].size()-1;
        int mid;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(target < matrix[a][mid])
            {
                end = mid - 1;
            }
            else if(target > matrix[a][mid])
            {
                start = mid + 1;
            }
            else if(target == matrix[a][mid])
            {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int n = (int)matrix[0].size() - 1;
        int end = (int)matrix.size() - 1;
        int mid;
        while(start <= end){
            mid = (start + end) / 2;
            if(target == matrix[mid][0])
            {
                return true;
            }
            if(target == matrix[mid][n])
            {
                return true;
            }
            if(target < matrix[mid][0])
            {
                end = mid - 1;
            }
            else if( target > matrix[mid][n])
            {
                start = mid + 1;
            }
            else if(target > matrix[mid][0] && target < matrix[mid][n])
            {
                return binary(matrix, mid, target);
            }
        }
        return false;
    }
};