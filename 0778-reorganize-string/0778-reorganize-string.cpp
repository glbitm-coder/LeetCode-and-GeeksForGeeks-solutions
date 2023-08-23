class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        int n = s.size();
        for(int i= 0; i < n; ++i){
            freq[s[i]]++;
        }
        int max_count = 0;
        char letter;
        for(auto &it:freq){
            if(it.second > max_count){
                max_count = it.second;
                letter = it.first;
            }
        }

        if(max_count > ceil((float)n / 2)){
            return "";
        }

        int i = 0, j = 1, k = 0;

        while(freq[letter] != 0){
            s[i] = letter;
            i += 2;
            freq[letter] = freq[letter] - 1;
        }
        for(auto &it:freq){
            k = it.second;
            while(k--){
                if(i >= n){
                    i = 1;
                }
                s[i] = it.first;
                i += 2; 
            }
        }
        return s;
    }
};