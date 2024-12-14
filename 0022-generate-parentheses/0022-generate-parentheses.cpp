class Solution {
public:

    vector<string> helper(int n){
        vector<string> ans;
        unordered_set<string> s;
        if(n == 1){
            ans.push_back("()");
            return ans;
        }
        for(auto it:helper(n-1)){
            for(int i = 0; i < it.size(); ++i){
                s.insert(it.substr(0,i + 1) + "()" + it.substr(i+1));
            }
        }
        for(auto it:s){
            ans.push_back(it);
        }

        return ans;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        return helper(n);
    }
};