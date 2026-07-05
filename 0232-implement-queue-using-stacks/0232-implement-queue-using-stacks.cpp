class MyQueue {
public:
    stack<int>main;
    stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!main.empty())
        {
            int top=main.top();
            helper.push(top);
            main.pop();
        }

        main.push(x);

        while(!helper.empty())
        {
            int top=helper.top();
            main.push(top);
            helper.pop();
        }
    }
    
    int pop() {
        int top=main.top();
        main.pop();
        return top;
    }
    
    int peek() {
        return main.top();
    }
    
    bool empty() {
        return main.empty();
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