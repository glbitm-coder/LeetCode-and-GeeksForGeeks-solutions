class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> s;
        int i = 0;
        int n = (long long int)tokens.size();
        long long int a, b;
        while(i < n)
        {
            if((tokens[i][0] == '+' || (tokens[i][0] == '-') || (tokens[i][0] == '*') || (tokens[i][0] == '/'))&&tokens[i].size() == 1)
            {   
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                if(tokens[i][0] == '+')
                {   
                    s.push(a + b);
                }
                else if(tokens[i][0] == '-')
                {
                    s.push(b - a);
                }
                else if(tokens[i][0] == '*')
                {
                    s.push(a * b);
                }
                else if(tokens[i][0] == '/')
                {
                    s.push((int)b / a);
                }
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
            ++i;
        }
        return s.top();
    }
};