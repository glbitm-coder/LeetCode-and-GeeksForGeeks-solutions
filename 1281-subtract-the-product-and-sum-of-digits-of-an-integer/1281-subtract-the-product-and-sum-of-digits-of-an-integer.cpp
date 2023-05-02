class Solution {
public:
    int subtractProductAndSum(int n) {
        long long int sum = 0;
        long long int prod = 1;
        while(n != 0)
        {
            sum += (long long int)n % 10;
            prod *= (long long int)n % 10;
            n = n / 10;
        }
        return prod - sum;
    }
};