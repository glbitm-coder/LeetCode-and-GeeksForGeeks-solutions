//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int ans = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                int count = 0;
                if(matrix[i][j] == 1){
                     if(j < matrix[0].size() - 1 && matrix[i][j + 1] == 0){
                    ++count;
                    }
                    if(i < matrix.size() - 1 && matrix[i + 1][j] == 0){
                        ++count;
                    }
                    if(j > 0 && matrix[i][j - 1] == 0){
                        ++count;
                    }
                    if(i > 0 && matrix[i - 1][j] == 0){
                        ++count;
                    }
                    if(j < matrix[0].size() - 1 && i < matrix.size() - 1 && matrix[i + 1][j + 1] == 0){
                        ++count;
                    }
                    if(j > 0 && i < matrix.size() - 1 && matrix[i + 1][j - 1] == 0){
                        ++count;
                    }
                    if(i > 0 && j < matrix[0].size() - 1 && matrix[i - 1][j + 1] == 0){
                        ++count;
                    }
                    if(j > 0 && i > 0 && matrix[i - 1][j - 1] == 0){
                        ++count;
                    }
                    if(count % 2 == 0 && count > 0) ++ans;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends