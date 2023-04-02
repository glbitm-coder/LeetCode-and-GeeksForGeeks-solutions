class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        for(int i = 0; i < spells.size(); ++i)
        {
            long long num = 0;
            if(success % spells[i] == 0)
            {
                num = success / spells[i];
            }
            else
            {
                num = (success / spells[i]) + 1;
            }
            long long ans = lower_bound(potions.begin(), potions.end(), num) - potions.begin() ;
            spells[i] = potions.size() - ans ;
        }
        return spells;
    }
};