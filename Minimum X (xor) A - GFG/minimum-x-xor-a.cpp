//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string binary(int a)
    {
        string bin = "";
        while(a != 0)
        {
            bin = to_string( a % 2) + bin;
            a = a / 2;
        }
        return bin;
    }
    int decimal(string s)
    {
        int powers = 0;
        int ans = 0;
        for(int i = s.size()-1; i >= 0; --i)
        {
            ans += int(s[i] - '0') * pow(2,powers);
            ++powers;
        }
        return ans;
    }
    int minVal(int a, int b) {
        // code here
        string bin_a = binary(a);
        string bin_b = binary(b);
        int count_1_b = 0;
        for(auto it:bin_b)
        {
            if(it == '1')
            {
                count_1_b++;
            }
        }
        int count_1_a = 0;
        for(auto it:bin_a)
        {
            if(it == '1')
            {
                count_1_a++;
            }
        }
        string ans_bin = "";
        int a_size = bin_a.size();
        int b_1_s_size = count_1_b;
        // if(a_size > b_1_s_size)
        // {
            if(count_1_a > count_1_b)
            {
                int temp_count = 0;
                for(int i = 0; i < a_size; ++i)
                {
                    if(temp_count == count_1_b)
                    {
                        bin_a[i] = '0';
                        continue;
                    }
                    if(bin_a[i] == '1')
                    {
                        temp_count++;
                    }
                }
                return decimal(bin_a);
            }
            else if(count_1_a < count_1_b)
            {
                int temp_count = count_1_b - count_1_a;
                for(int i = a_size - 1; i>= 0; --i)
                {
                    if(bin_a[i] == '0' && temp_count != 0)
                    {
                        bin_a[i] = '1';
                        --temp_count;
                    }
                }
                return decimal(bin_a);
            }
            else
            {
                return a;
            }
        // }
        return decimal(ans_bin);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends