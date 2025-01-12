/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    unordered_map<Node*, bool> visited;
    void createNodes(Node* node){
        if(node == NULL) return;
        if(visited[node]) return;
        visited[node] = true;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto it: node->neighbors){
            createNodes(it);
        }
    }

    void connect(Node* node){
        if(node == NULL) return;
        if(visited[node]) return;
        visited[node] = true;
        for(auto it:node->neighbors){
            mp[node]->neighbors.push_back(mp[it]);
            connect(it);
        }
    }
    
    Node* cloneGraph(Node* node) {
        createNodes(node);
        visited.clear();
        connect(node);
        return mp[node];
    }
};