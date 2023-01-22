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
    void helper(string curr, vector<string>& curr_ans, vector<vector<string>>& ans)
    {
        if(curr.size() == 0)
        {
            ans.push_back(curr_ans);
        }
        for(int i = 0; i < curr.size(); ++i)
        {
            string prefix = curr.substr(0,i+1);
            string ros = curr.substr(i + 1);
            if(isPalindrome(prefix))
            {
                curr_ans.push_back(prefix);
                helper(ros, curr_ans, ans);
                curr_ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr_ans;
        helper(s, curr_ans, ans);
        return ans;
    }
};