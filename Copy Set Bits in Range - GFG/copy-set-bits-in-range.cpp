//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    string DecimalToBinary(int num)
    {
        string str;
          while(num){
          if(num & 1) // 1
            str+='1';
          else // 0
            str+='0';
          num>>=1; // Right Shift by 1 
        }   
        reverse(str.begin(), str.end());
        return str;
    }
    
    int binaryToDecimal(string n)
    {
        string num = n;
        int dec_value = 0;
     
        // Initializing base value to 1, i.e 2^0
        int base = 1;
     
        int len = num.length();
        for (int i = len - 1; i >= 0; i--) {
            if (num[i] == '1')
                dec_value += base;
            base = base * 2;
        }
     
        return dec_value;
    }
 
    int setSetBit(int x, int y, int l, int r){
        // code here
        string a = DecimalToBinary(x);
        string b = DecimalToBinary(y);
        int n1 = a.size();
        int n2 = b.size();
        int n = n1 > n2 ? n1 : n2;
        if(n > n2){
            for(int i = 1; i <= n - n2; ++i)
                b = '0' + b;
        }
        if(n > n1){
            for(int i = 1; i <= n - n1; ++i){
                a = '0' + a;
            }
        }
        for(int i = l; i <= r; i++){
            if(a[a.size() - i] == '0' && b[b.size() - i] == '1'){
                a[a.size() - i] = '1';
            }
        }
        return binaryToDecimal(a);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends