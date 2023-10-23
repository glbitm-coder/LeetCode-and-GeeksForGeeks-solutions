class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n <= 0) return false;
        if(n % 4 != 0) return false;
        int a = log2(n);
        float b = floor(log2(n));
        float c = ceil(log2(n));
        if(b != c) return false;
        if(a % 2 != 0) return false;

        return true;
    }
};