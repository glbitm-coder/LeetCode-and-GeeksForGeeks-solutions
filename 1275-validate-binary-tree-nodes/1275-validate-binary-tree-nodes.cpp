class Solution {
public:
    bool dfs(int src, int n, vector<int>& leftChild, vector<int>& rightChild, vector<bool> &visited){
        if(visited[src]){
            return false;
        }
        visited[src] = true;
        if(leftChild[src] == -1 && rightChild[src] == -1){
            return true;
        }
        bool leftVal = true;
        if(leftChild[src] != -1){
            leftVal = dfs(leftChild[src], n, leftChild, rightChild, visited);
        }
        
        bool rightVal = true;
        if(rightChild[src] != -1){
            rightVal = dfs(rightChild[src], n, leftChild, rightChild, visited);
        }
        if(leftVal && rightVal) return true;
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int count = 0;
        unordered_set<int> s;
        for(int i = 0; i < n; ++i){
            if(leftChild[i] != -1){
                ++count;
                s.insert(leftChild[i]);
            }
            if(rightChild[i] != -1){
                ++count;
            }
        }
        if(count != n - 1) return false;

        
        for(int i = 0; i < n; ++i){
            if(s.find(rightChild[i]) != s.end()){
                return false;
            }
        }
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            fill(visited.begin(), visited.end(), false);
            if(dfs(i, n, leftChild, rightChild, visited) == false){
                return false;
            }
        }
        return true;
    }
};