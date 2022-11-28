class MyQueue {
public:
     stack<int> first_stack, last_stack;
        int top;
    MyQueue() {
       
    }
    
    void push(int x) {
        first_stack.push(x);
    }
    
    int pop() {
        int a;
        if(last_stack.empty())
        {
            while(!first_stack.empty())
            {
                last_stack.push(first_stack.top());
                first_stack.pop();
            }
           
        }
         a = last_stack.top();
        last_stack.pop();
        return a;
    }
    
    int peek() {
        int a;
        if(last_stack.empty())
        {
            while(!first_stack.empty())
            {
                last_stack.push(first_stack.top());
                first_stack.pop();
            }
           
        }
         a = last_stack.top();
        return a;
    }
    
    bool empty() {
        return last_stack.empty() and first_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */