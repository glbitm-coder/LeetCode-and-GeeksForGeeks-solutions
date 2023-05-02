class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans= 0;
        while(n != 0)
        {
            auto c = n % 2;
            n = n / 2;
            if(c == 1) ans += 1;
        }
        return ans;
    }
};