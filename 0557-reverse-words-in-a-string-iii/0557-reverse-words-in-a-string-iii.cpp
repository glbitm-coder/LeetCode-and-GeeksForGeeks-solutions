class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' '){
                word += s[i];
            } else{
                reverse(word.begin(), word.end());
                ans += word + ' ';
                word = "";
            }
        }
        reverse(word.begin(), word.end());
        ans += word;
        return ans;
    }
};