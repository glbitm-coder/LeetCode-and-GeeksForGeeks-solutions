//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution
{
public:
    bool static cmp(string &a, string &b)
    {
        if(b.size() != a.size())
        {
            return a.size() > b.size();
        }
        else
        {
            for(int i = 0; i < (int)a.size(); ++i)
            {
                if(a[i] != b[i])
                {
                    return a[i] < b[i];
                }
            }
        }
        
    }

    bool iseligible(string word, unordered_set<string> &s)
    {
        int n = (int)word.size();
        while (!word.empty())
        {
            if(s.find(word) == s.end())
            {
                return false;
            }
            word.pop_back();
        }
        return true;
    }
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(), words.end(), cmp);
        int n = (int)words.size();
        unordered_set<string> s;
        for(int i = 0; i < n; ++i)
        {
            s.insert(words[i]);
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(iseligible(words[i],s))
            {
                return words[i];
            }
        }
        return "";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends