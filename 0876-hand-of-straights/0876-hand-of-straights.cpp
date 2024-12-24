class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());

        map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[hand[i]]++;
        }

        int count = groupSize - 1, start = 0;
        for(int i = 0; i < n / groupSize; ++i){
            
            start = mp.begin()->first;
            count = groupSize - 1;
            mp[start]--;
            
            if(mp[start] == 0) mp.erase(start);
            
            while(count--){
                if(mp.find(start + 1) == mp.end()){
                    
                    return false;
                }
                else{
                    mp[start + 1]--;
                    if(mp[start + 1] == 0) mp.erase(start + 1);
                }
                ++start;
            }
        }
        return true;
    }
};