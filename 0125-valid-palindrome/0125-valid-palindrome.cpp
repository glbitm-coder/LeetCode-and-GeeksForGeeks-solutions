class Solution {
public:
    bool isPalindrome(string s) {
        
        for(int i = 0, j = s.size() - 1; i <= j;){
            if(iswalnum(s[i])){
                if(iswalnum(s[j])){
                    if(tolower(s[i]) != tolower(s[j])){
                        return false;
                    }
                    else{
                        ++i;
                        --j;
                    }
                }
                else{
                    --j;
                }
            }
            else{
                ++i;
            }
        }
        return true;
    }
};