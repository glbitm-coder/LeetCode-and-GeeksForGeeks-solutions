class Solution {
public:
    bool isValid(string s) {
        stack<char> sck;
        for(int i = 0; i < (int)s.size(); ++i)
        {
            if(sck.empty())
            {
                if(s[i] == ']' || s[i] == '}' || s[i] == ')')
                {
                    return false;
                }
            }
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                sck.push(s[i]);
            }
            else{
                if(s[i] == ')')
                {
                    if(sck.top() != '(')
                    {
                        return false;
                    }
                    else{
                        sck.pop();
                    }
                    
                }
                else if(s[i] == '}')
                {
                    if(sck.top() != '{')
                    {
                        return false;
                    }
                    else{
                        sck.pop();
                    }
                }
                else{
                     if(sck.top() != '[')
                    {
                        return false;
                    }
                    else{
                        sck.pop();
                    }
                }
            }
        }
        if(sck.empty())
        {
            return true;
        }
        return false;
    }
};