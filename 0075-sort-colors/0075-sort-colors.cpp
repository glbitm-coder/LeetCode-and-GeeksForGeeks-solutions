class Solution {
public:
    void swap(int &a, int &b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = (int)nums.size();
        
        if(n == 0 || n == 1)
        {
            return ;
        }
        else if(n == 2)
        {
            if(nums[0] <= nums[1])
            {
                return ;
            }
            else{
                swap(nums[0], nums[1]);
            }
        }
        else
        {
            int start = 0, end = n - 1;
            for(int i = 0 ; i <= end; )
            {
                if(nums[i] == 0)
                {
                    swap(nums[i], nums[start]);
                    ++start;
                    ++i;
                }
                else if(nums[i] == 1)
                {
                    ++i;
                }
                else
                {
                    swap(nums[i], nums[end]);
                    --end;
                }
            }
        }
    }
};