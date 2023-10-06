class Solution {
public:
    int integerBreak(int n) {
        unordered_map<int, int> freq;
        freq[2] = 0;
        freq[3] = 0;
        if(n == 1 || n == 2) return 1;
        if( n == 3) return 2;
        while(n != 0){
            if(n == 1){
                freq[3]--;
                freq[2] += 2;
                break;
            } else if(n == 2){
                freq[2]++;
                break;
            } else{
                freq[3]++;
                n = n - 3;
            }
        }
        int ans = 1;
        for(auto it:freq){
            for(int i = 0; i < it.second; ++i){
                ans *= it.first;
            }
        }
        return ans;
    }
};