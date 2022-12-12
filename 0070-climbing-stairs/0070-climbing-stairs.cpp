class Solution {
    
public:
    int a[46];
    void ans()
    {
        a[1] = 1;
        a[2] = 2;
        for(int i = 3; i < 46; ++i)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
    
    int climbStairs(int n) {
        ans();
       return a[n];
    }
};