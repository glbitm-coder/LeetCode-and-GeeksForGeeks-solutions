class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;


        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[hand[i]]++;
        }
        int start = 0;
        for(int i = 0; i < n; ++i){
            start = hand[i];
            while(mp[start - 1] > 0){
                start = start - 1;
            }
            while(start <= hand[i]){
                while(mp[start] > 0){
                    for(int j = start; j < start + groupSize; ++j){
                        if(mp[j] == 0) return false;
                        --mp[j];
                    }
                }
                ++start;
            }
        }
        return true;
    }
};