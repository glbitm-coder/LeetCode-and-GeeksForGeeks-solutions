class Solution {
public:
    bool isValid(string s) {
        string in = "({[";
        string out = ")}]";
        stack<char> st;
        for(auto it:s){
            if(in.find(it) != string::npos){
                st.push(it);
            }
            else{
                if(st.empty()) return false;
                char t = st.top();
                if((t == in[0] && it == out[0]) || (t == in[1] && it == out[1]) || (t == in[2] && it == out[2])){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};