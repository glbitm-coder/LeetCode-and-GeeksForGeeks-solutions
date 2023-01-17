class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_flip = 0;
        int count_1 = 0;
        for(auto it:s)
        {
            if(it == '1') count_1++;
            else{
                count_flip++;
                count_flip = min(count_flip, count_1);
            }
        }
        return count_flip;
    }
};