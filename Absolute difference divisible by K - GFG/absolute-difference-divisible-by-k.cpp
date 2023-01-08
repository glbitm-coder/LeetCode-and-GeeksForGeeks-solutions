//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
        vector<long long> rem(k, 0);
        long long ans = 0;
        
        for(int i = 0; i < n ; ++i)
        {
            rem[arr[i] % k]++;
        }
        
        for(int i = 0; i < k; ++i)
        {
            //RHS is Number of pairs we can make through each remainder - n *(n-1)/2
            // Ans denotes total number of these pairs
            ans += (rem[i] * (rem[i] -1)) / 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends