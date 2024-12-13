class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int a = 0, b = 0, c = 0;
        for(auto it:tokens){
            if(it == "+" || it == "*" || it == "-" || it == "/"){
                a = stoi(s.top());
                s.pop();
                b = stoi(s.top());
                s.pop();
                if(it == "+"){
                    c = a + b;
                }
                else if(it == "-"){
                    c = b - a;
                }
                else if(it == "*"){
                    c = b * a;
                }
                else if(it == "/"){
                    c = b / a;
                }
                s.push(to_string(c));
            }
            else{
                s.push(it);
            }
        }
        return stoi(s.top());
    }
};