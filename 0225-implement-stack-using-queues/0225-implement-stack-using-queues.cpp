class MyStack {
public:
    queue<int>main;
    queue<int>helper;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!main.empty())
        {
            int front=main.front();
            helper.push(front);
            main.pop();
        }

        main.push(x);

        while(!helper.empty())
        {
            int front=helper.front();
            main.push(front);
            helper.pop();
        }
    }
    
    int pop() {
        int top=main.front();
        main.pop();
        return top;
    }
    
    int top() {
        return main.front();
    }
    
    bool empty() {
        return main.empty();
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