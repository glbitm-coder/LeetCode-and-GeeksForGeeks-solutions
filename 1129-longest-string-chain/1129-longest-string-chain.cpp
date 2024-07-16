class Solution {
public:
    bool isValid(string s1, string s2){
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 - 1 != n2){
            return false;
        }

        int count = 0;
        for(int i = 0, j = 0; i < n1 && j < n2;){
            if(s1[i] == s2[j]){
                count++;
                ++i;
                ++j;
            }
            else{
                ++i;
            }
        }

        if(count == n2){
            return true;
        }
        return false;
    }

    bool static cmp(string &a, string &b){

        if(a.size() != b.size()){
            return a.size() < b.size();
        }
        else{
            return a < b;
        }
    }

    int longestStrChain(vector<string>& words) {
        
        int n = words.size();
        vector<int> dp(n, 0);

        sort(words.begin(), words.end(), cmp);

        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < n; ++i){
            int maxi = 1;
            for(int j = 0; j < i; ++j){
                if(isValid(words[i], words[j])){
                    maxi = max(maxi, dp[j] + 1);
                }
            }
            dp[i] = maxi;
            ans = max(ans, maxi);
        }

        return ans;
    }
};