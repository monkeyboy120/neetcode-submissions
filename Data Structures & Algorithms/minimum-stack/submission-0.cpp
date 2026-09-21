class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        val = std::min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();    
    }
    
    int top() {
       return stack.top(); 
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> stack; // normal stack
    std::stack<int> minStack; // always store min at top
};
