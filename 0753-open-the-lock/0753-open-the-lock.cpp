class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        unordered_set<string> dead;
        
        q.push({"0000", 0});
        for(auto it:deadends) dead.insert(it);
        
        if(dead.find("0000") != dead.end()) return -1;
        
        pair<string,int> pq;
        string str ="";
        int num = 0;
        int ans = INT_MAX;
        while(!q.empty()){

            pq = q.front();
            str = pq.first;
            num = pq.second;
            
            q.pop();
            
            if(str == target){
                ans = min(ans, num);
            }
            for(int i = 0; i < 4; ++i){
                int temp = str[i] - '0';
                string t = str;
                t[i] = '0' + (temp + 1) % 10;
                if(dead.find(t) == dead.end()){
                    dead.insert(t);
                    q.push({t, num + 1});
                }
                t[i] = '0' + (10 + temp - 1) % 10;
                if(dead.find(t) == dead.end()){
                    dead.insert(t);
                    
                    q.push({t, num + 1});
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};