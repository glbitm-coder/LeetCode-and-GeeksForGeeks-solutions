class Solution {
public:
   

    int bfs(int curr, string target, vector<string> &wordList, vector<bool> &visited, int n)
    {
        queue<pair<string,int>> q;
        q.push({wordList[curr],1});

        unordered_set<string> st(wordList.begin(), wordList.end());

        st.erase(wordList[curr]);

        while(!q.empty()){
            pair<string,int> now = q.front();
            string word = now.first;
            int level = now.second;
            q.pop();

            if(word == target){
                return level;
            }
            
            for(int i = 0; i < word.size(); ++i){
                char original = word[i];
                for(char j = 'a'; j <= 'z'; ++j){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, level + 1});
                    }
                }
                word[i] = original;
            }            
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        
        bool isContain = false;
        bool isContainEndWord = false;

        for(int i = 0; i < n; ++i){
            if(wordList[i] == endWord)
            {
                isContainEndWord = true;
                break;
            }
        }

        if(!isContainEndWord)
        {
            return 0;
        }


        int value;
        for(int i = 0; i < n; ++i){
            vector<bool> visited(n, false);
            vector<int> ans(n, INT_MAX);
            if(wordList[i] == beginWord){
                isContain = true;
                value = bfs(i, endWord, wordList, visited, n);
            }
        }
        
        if(!isContain){
            wordList.push_back(beginWord);
            n = n + 1;
            vector<bool> visited(n, false);
            vector<int> ans(n, INT_MAX);
            value = bfs(n - 1, endWord, wordList, visited, n);
        }   

        if(value == INT_MAX)
            return 0;

        return value;
    }
};