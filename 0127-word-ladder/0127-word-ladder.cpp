class Solution {
public:
    bool isSatisfied(string &beginWord, string &next){
        int count = 0;
        for(int i = 0; i < beginWord.size(); ++i){
            if(beginWord[i] != next[i]){
                ++count;
            }
            if(count == 2) return false;
        }
        return true;
    }
    void createGraph(string beginWord, vector<string> &wordList, unordered_map<string, vector<string>> &mp){
        for(auto it:wordList){
            for(auto i:wordList){
                if(it != i && isSatisfied(it, i)){
                    mp[it].push_back(i);
                }
            }
        }
        if(mp.find(beginWord) != mp.end()) return;
        for(auto i:wordList){
            if(i != beginWord && isSatisfied(i, beginWord)){
                mp[beginWord].push_back(i);
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> visited;
        for(auto it:wordList){
            visited[it] = false;
        }
        unordered_map<string, vector<string>> mp;
        createGraph(beginWord, wordList, mp);
        int ans = 0;
        queue<string> q;
        q.push(beginWord);
        q.push("");
        string str;
        while(!q.empty()){
            str = q.front();
            q.pop();
            if(str.size() == 0){
                ++ans;
                if(q.empty()) return 0;
                q.push(str);
            }
            else{
                if(str == endWord) return ans + 1;
                for(auto it: mp[str]){
                    if(!visited[it] && isSatisfied(str, it)){

                        q.push(it); 
                        visited[it] = true; 
                    }
                }
            }
        }
        return ans;
    }
};