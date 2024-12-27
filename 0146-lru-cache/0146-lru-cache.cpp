struct Node {
    public:
      int key;
      int val;
      Node *next, *prev;
      Node(int k, int v){
        key = k;
        val = v;
      }
 };

class LRUCache {
public:
    int cap;
    unordered_map<int,Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        mp[node->key] = node;
    }

    void removeNode(Node* node){
        Node* temp = node->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        mp.erase(node->key);
    }
    
    void moveToFront(Node* node){
        removeNode(node);
        addNode(node);
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        moveToFront(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key]->val = value;
            moveToFront(mp[key]);
        }
        else{
            if(mp.size() == cap){
                removeNode(tail->prev);
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */