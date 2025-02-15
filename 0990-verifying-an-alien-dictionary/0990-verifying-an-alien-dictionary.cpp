class Solution {
public:
    void createGraph(string order, unordered_map<char, unordered_set<char>> &mp){
        for(int i = 0; i < order.size(); ++i){
            for(int j = i + 1; j < order.size(); ++j){
                mp[order[i]].insert(order[j]);
            }
        }
    }
    // bool isStringValid(string &str, unordered_map<char, unordered_set<char>> &mp){

    // }

    bool isPairValid(string &str1, string &str2, unordered_map<char, unordered_set<char>> &mp){
        int minLength = min(str1.size(), str2.size());
        if(str1.substr(0,minLength) == str2.substr(0, minLength)){
            if(str1.size() > str2.size()) return false;
        }
        else{
            int i = 0;
            while(str1[i] == str2[i]){
                ++i;
            }
            if(mp[str2[i]].find(str1[i]) != mp[str2[i]].end()){
                return false;
            }
        }

        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, unordered_set<char>> mp;
        createGraph(order, mp);
        for(int i = 0; i < words.size(); ++i){
            // bool isVal = isStringValid(words[i], mp);
            // if(!isVal) return false;
            for(int j = i + 1; j < words.size(); ++j){
                bool isPair = isPairValid(words[i], words[j], mp);
                if(!isPair) return false;
            }
        }
        return true;
    }
};