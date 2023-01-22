//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        bool flag= true;
        stack<char> st;
        for(int i = s.size() - 1; i >= 0; --i)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if(st.top() != s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        string ans = "";
        if(st.empty()) return "-1";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends