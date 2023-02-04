class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;
        for(int i = 0; i < s1.size(); ++i)
        {
            mp1[s1[i]]++;
        }
        if(s1.size() > s2.size()) return false;
        for(int j = 0; j <= s2.size() - s1.size(); ++j)
        {
            mp2 = mp1;
            for(int i = j; i < j + s1.size(); ++i)
            {
                if(mp2.find(s2[i]) == mp2.end())
                {
                    break;
                }
                else
                {
                    mp2[s2[i]]--;
                }

                if(mp2[s2[i]] == 0)
                {
                    mp2.erase(s2[i]);
                }
                if(mp2.empty()){
                    return true;
                }

            }
            mp2.clear();
        }
        return false;
    }
};