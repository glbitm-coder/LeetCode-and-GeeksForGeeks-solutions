//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
    vector<int> prime;
    public: Solution()
    {
        // Every index of prime stores zero or one
        // If prime[i] is zero means i is not a prime
        // If prime[i] is one means i is a prime
         // every num isprime
         prime.resize(10000,1);
        prime[1]=0; 
        for(int i=2; i<=9999; i++)
        {
            if(prime[i]==1)// mark its multiple as false
            {
                for(int j=i*i; j<=9999; j+=i)
                prime[j]=0; // mark not prime
            }
        }
    }
  public:
    int shortestPath(int num1,int num2)
    {   
        // Complete this function using prime vector
        vector<int> ans(10000,-1);
        vector<bool> vis(10000);
        queue<int> q;;
        q.push(num1); vis[num1]=false; ans[num1]=0;
        
        while(!q.empty())
        {
            int curr =  q.front();
            q.pop();
            // if vis , skip
            if(vis[curr]) continue;
            
            vis[curr]=true;  //marking the node visited.
            
            string x = to_string(curr);
            for(int i=0; i<4; i++)
            {
                for(char ch='0'; ch<='9'; ch++)
                {
                    // should be a four digit prime number with no leading zeros.
                    if ( (ch=='0'&&i==0) || ch==x[i])
                    continue;
                    
                    string y = x.substr(0,i) + ch + x.substr(i+1);
                    
                    //conver in int and pushto Q if cond are satisfies
                    int z = stoi(y);
                    if(prime[z]==1 && ans[z]==-1)
                    {
                        ans[z] = 1+ans[curr];
                        q.push(z);
                    }
                }
            }
        }
        return ans[num2];
        
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends