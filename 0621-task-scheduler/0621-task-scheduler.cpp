class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char,int> mp;
        for(int i = 0; i < tasks.size(); ++i){
            mp[tasks[i]]++;
        }

        for(auto it:mp){
            pq.push(it.second);
        }
        vector<int> temp;
        int res = 0, ans = 0;
        while(!pq.empty()){
            int cycle = n + 1;
            ans = 0;
            for(int i = 0; i < cycle && !pq.empty(); ++i){
                ++ans;
                temp.push_back(pq.top() - 1);
                pq.pop();
            }
            for(auto it:temp){
                if(it != 0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                res += ans;
            }
            else{
                res += cycle;
            }
            temp.clear();
        }
        return res;
    }
};