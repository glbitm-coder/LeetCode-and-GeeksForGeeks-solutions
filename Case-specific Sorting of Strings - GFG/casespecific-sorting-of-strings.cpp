//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        int j = -1;
        string str2 = str;
        sort(str.begin(), str.end());
        for(int i = 0; i < n; ++i)
        {
            if(islower(str[i]))
            {
                j = i;
                break;
            }
        }
        if(j == -1) return str;
        int k = 0;
        for(int i = 0; i < n; ++i)
        {
            if(isupper(str2[i]))
            {
                str2[i] = str[k];
                k++;
            }
            else
            {
                str2[i] = str[j];
                ++j;
            }
        }
        return str2;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends