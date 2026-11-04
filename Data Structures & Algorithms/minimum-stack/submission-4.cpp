class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        val = std::min(val, minStk.empty() ? val : minStk.top()); // val is minimum
        minStk.push(val); // minStack holds curr min
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }

private:
    stack<int> stk;
    stack<int> minStk;
};
