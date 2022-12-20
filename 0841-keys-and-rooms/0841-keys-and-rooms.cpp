class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int>> mp;
        int n = (int)rooms.size();
        for(int i =0 ; i < n; ++i)
        {
            mp[i] = rooms[i];
        }
        queue<int> q;
        q.push(0);
        vector<int> visited(n , 0);
        visited[0] = 1;
        int count = 1;
        while(!q.empty())
        {
            if(count == n)
            {
                return true;
            }
            int curr = q.front();
            q.pop();
            for(int i = 0; i < mp[curr].size(); ++i)
            {
                if(!visited[mp[curr][i]])
                {
                    q.push(mp[curr][i]);
                    visited[mp[curr][i]] = 1;
                    count++;
                }
            }
        }
        if(count == n)
        {
            return true;
        }
        return false;
    }
};