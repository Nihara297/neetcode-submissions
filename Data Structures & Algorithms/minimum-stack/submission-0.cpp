class MinStack {
    stack<int>s;
    stack<int>ms;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ms.empty()){
            ms.push(val);
        }
        else{
            ms.push(min(val, ms.top()));
        }
    }
    
    void pop() {
        s.pop();
        ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
