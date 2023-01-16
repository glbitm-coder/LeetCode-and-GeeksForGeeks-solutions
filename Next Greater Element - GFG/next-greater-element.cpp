//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        stack<int> s;
        for(int i = n - 1; i >= 0; --i)
        {
            if(i == n - 1) 
            {
                s.push(arr[i]);
                arr[i] = -1;
            }
            else
            {
                while(s.top() < arr[i])
                {
                    s.pop();
                    if(s.empty()) break;
                }
                if(s.empty())
                {
                    s.push(arr[i]);
                    arr[i] = -1;
                }
                else
                {
                    int a = s.top();
                    s.push(arr[i]);
                    arr[i] = a;
                }
            }
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends