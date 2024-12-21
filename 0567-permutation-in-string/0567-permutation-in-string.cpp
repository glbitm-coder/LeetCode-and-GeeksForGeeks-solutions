class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> charFreq(26,0);
        int n1 = s1.size(), n2 = s2.size();
        for(int i = 0; i < n1; ++i){
            charFreq[s1[i] - 'a']++;
        }

        vector<int> chFreq(26,0);
        if(n1 > n2){
            return false;
        }
        for(int i = 0, j = n1; i < j; ++i){
            chFreq[s2[i] - 'a']++;
        }
        if(chFreq == charFreq){
            return true;
        }
        for(int i = 0, j= n1; j < n2; ++i,++j){
            chFreq[s2[i] - 'a']--;
            chFreq[s2[j] - 'a']++;
            if(chFreq == charFreq){
                return true;
            }
        }
        return false;
    }
};