class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string ans = "";
        if(numRows == 1) return s;
        for(int i = 0; i < numRows; ++i)
        {
            int jump = 2 * (numRows - 1);
            for(int j = i; j < n; j += jump)
            {
                ans += s[j];
                int midJumps = j + jump - 2 * i;   
                if (i > 0 && i < numRows - 1 && midJumps < n) 
                    ans += s[midJumps];
            }
        }
        return ans;
    }
};