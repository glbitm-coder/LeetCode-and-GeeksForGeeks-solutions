class Solution {
public:
    bool underCat(vector<int> &a1, vector<int> &a2){
        long long int x1 = a1[0];
        long long int x2 = a2[0];
        long long int y1 = a1[1];
        long long int y2 = a2[1];
        long long int  r = (long long int)a1[2] * a1[2];
        long long int d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        if(r >= d){
            return true;
        }
        return false;
    }
    int dfs(int curr, vector<vector<int>>& bombs, vector<bool> &visited){
        if(curr == bombs.size()) return 0;
        int x = bombs[curr][0];
        int y = bombs[curr][1];
        int r = bombs[curr][2];
        int count = 0;
        visited[curr] = true;
        for(int i = 0; i < bombs.size(); ++i){
            if(i != curr && !visited[i]){
                if(underCat(bombs[curr], bombs[i])){
                    ++count;
                    count += dfs(i, bombs, visited);
                }
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        
        int ans = 0;
        for(int i = 0; i < bombs.size(); ++i){
            vector<bool> visited(bombs.size(), false);    
            
            int val = dfs(i, bombs, visited);
            ans = max(ans, val);
        }
        
        
        return ans + 1;
    }
};


