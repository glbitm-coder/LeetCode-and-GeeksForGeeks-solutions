class Solution {
public:
    pair<int,int> dp[501][501] = {};
    pair<int,int> helper(vector<int> &piles, int left, int right){
        if(left > right)
            return {0,0};
        if(dp[left][right].first != 0)
            return dp[left][right];

        pair<int,int> leftPick = helper(piles, left + 1, right);
        pair<int,int> rightPick = helper(piles, left, right - 1);
        if(piles[left] + leftPick.second > piles[right] + rightPick.second)
            return dp[left][right] = {piles[left] + leftPick.second, leftPick.first};
        return dp[left][right] = {piles[right] + rightPick.second, rightPick.first};
    }
    bool stoneGame(vector<int>& piles) { 
        int aliceTotal = 0, bobTotal = 0;
        pair<int,int> val =  helper(piles, 0, piles.size() - 1);
        return val.first > val.second;
    }
};