//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int curr_sum = 0;
        int j = 0;
        int start_point =0, end_point = 0;
        bool flag = true;
        vector<int> ans;
        if(s == 0){
            ans.push_back(-1);
            return ans;
        }
        for(int i = 0; i < n; ++i)
        {
            curr_sum += arr[i];
            while(curr_sum > s && j < n)
            {
                curr_sum -= arr[j];
                ++j;
            }
            if(curr_sum == s){
                end_point = i;
                start_point = j;
                flag = false;
                break;
            }
        }
        if(flag){
            ans.push_back(-1);
            return ans;
        } 
        ans.push_back(start_point + 1);
        ans.push_back(end_point + 1);
        return ans;
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends