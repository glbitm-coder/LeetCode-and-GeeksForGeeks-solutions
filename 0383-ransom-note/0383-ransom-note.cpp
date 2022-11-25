class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n1 = (int)ransomNote.size();
        int n2 = (int)magazine.size();
        unordered_map<char, int> mp1, mp2;
        for(int i = 0; i < n1; ++i)
        {
            mp1[ransomNote[i]]++;
        }
        for(int i = 0; i < n2; ++i)
        {
            mp2[magazine[i]]++;
        }
        for(int i = 0; i < n1; ++i)
        {
            if(mp2.find(ransomNote[i]) == mp2.end())
            {
                return false;
            }
            else{
                if(mp2[ransomNote[i]] >= mp1[ransomNote[i]])
                {
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};