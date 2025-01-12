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
    void createNodes(Node* node, unordered_map<Node*, bool> &visited){
        if(node == NULL) return;
        if(visited[node]) return;
        visited[node] = true;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(auto &it: node->neighbors){
            createNodes(it, visited);
        }
    }

    void connect(Node* node, unordered_map<Node*, bool> &visited){
        if(node == NULL) return;
        if(visited[node]) return;
        visited[node] = true;
        for(auto &it:node->neighbors){
            mp[node]->neighbors.push_back(mp[it]);
            connect(it, visited);
        }
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, bool> visited;
        createNodes(node, visited);
        visited.clear();
        connect(node, visited);
        return mp[node];
    }
};