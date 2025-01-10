class Solution {
public:
    map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    void backtrack(int idx, string digits, vector<string> &ans, string curr){
        if(digits.size() == curr.size()){
            ans.push_back(curr);
            return;
        }
        string str = mp[digits[idx]];
        for(int i = 0; i < str.size(); ++i){
            backtrack(idx + 1, digits, ans, curr + str[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        string curr;
        vector<string> ans;
        if(digits.size() == 0) return ans;
        backtrack(0, digits, ans, curr);
        return ans;
    }
};