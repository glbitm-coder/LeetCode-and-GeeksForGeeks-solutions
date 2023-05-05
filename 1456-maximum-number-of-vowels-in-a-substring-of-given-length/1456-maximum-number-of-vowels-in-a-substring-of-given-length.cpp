class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int maximum = 0, count = 0;
       
        for(int i = 0; i < s.size() && i < k; ++i)
        {
            if(isVowel(s[i]))
            {
                count++;
            }
        }
        maximum = count;
        for(int i = 1, j = k; i < s.size() && j < s.size(); ++i, ++j)
        {
            if(isVowel(s[i - 1]))
            {
                count--;
            }
            if(isVowel(s[j]))
            {
                count++;
            }
            maximum = max(maximum, count);
        }
        return maximum;
    }
};