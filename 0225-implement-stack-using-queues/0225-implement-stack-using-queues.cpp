class MyStack {
public:
    queue<int> q1, q2;
    int curr_size;
    MyStack() {
        curr_size = 0;
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        ++curr_size;
        q1 = q2;
        q2 = queue<int>();
    }
    
    int pop() {
        if(q1.empty()) 
            return -1;
        int val = q1.front();
        q1.pop();
        --curr_size;
        return val;
    }
    
    int top() {
        if(q1.empty())
            return -1;
        return q1.front();
    }
    
    bool empty() {
        return curr_size == 0 ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */