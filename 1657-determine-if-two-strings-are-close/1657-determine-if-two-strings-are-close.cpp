class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> mp1, mp2;
        unordered_set<char> st1, st2;
        int n1 = (int)word1.size();
        int n2 = (int)word2.size();
        if(n1 != n2)
        {
            return false;
        }
        for(int i = 0; i < n1; ++i)
        {
            st1.insert(word1[i]);
            mp1[word1[i]]++;
        }
        vector<int> freq_word1_char;
        for(auto it: mp1)
        {
            freq_word1_char.push_back(it.second);
        }
        sort(freq_word1_char.begin(), freq_word1_char.end());
        
        for(int i = 0; i < n2; ++i)
        {
             st2.insert(word2[i]);
            mp2[word2[i]]++;
        }
        vector<int> freq_word2_char;
        for(auto it: mp2)
        {
            
            freq_word2_char.push_back(it.second);
        }
        sort(freq_word2_char.begin(), freq_word2_char.end());
        
        for(int i = 0; i < (int)freq_word1_char.size(); ++i)
        {
            if(freq_word2_char[i] != freq_word1_char[i])
            {
                return false;
            }
        }
        if(st1 != st2)
        {
            return false;
        }
        return true;
    }
};