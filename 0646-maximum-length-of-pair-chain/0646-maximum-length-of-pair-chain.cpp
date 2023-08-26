class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        if(n <= 1){
            return 1;
        }

        sort(pairs.begin(), pairs.end(), cmp);
        int prev = pairs[0][1];
        int count = 1;
        for(int i = 1; i < n; ++i){
            if(pairs[i][0] > prev){
                ++count;
                prev = pairs[i][1];
            }
        }
        return count;
    }
};