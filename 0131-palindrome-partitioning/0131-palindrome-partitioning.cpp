class Solution {
public:
    bool isPalindrome(string s)
    {
        if(s.size() == 1) return true;
        int i = 0, j = s.size()-1;
        while(i <= j)
        {
            if(s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    
    void backtrack(vector<string> &currAns, string s, vector<vector<string>> &ans, int n)
    {
        for(auto it:currAns){
            int val;
            val += it.size();
            if(val == n){
                ans.push_back(currAns);
                return;
            }
            else if(val > n) return;
        }

        string palindrome = "";
        for(int i = 0; i < s.size(); ++i){
            palindrome += s[i];
            if(isPalindrome(palindrome)){
                string str = s.substr(i + 1);
                currAns.push_back(palindrome);
                backtrack(currAns, str, ans, n);
                currAns.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> currAns;
        vector<vector<string>> ans;
        backtrack(currAns, s, ans, s.size());
        return ans;
    }
};