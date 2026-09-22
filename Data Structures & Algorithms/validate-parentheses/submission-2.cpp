class Solution {
public:
    bool isValid(string s) {
       std::stack<char> stack;

       std::unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['},
       };

       for(char c : s) {
        if(pairs.count(c)) { // if end char
            if(!stack.empty() && stack.top() == pairs[c]) {
                stack.pop(); // good pair, remove from stack
            } else {
                return false; // bad pair, fail
            }
        } else {
            stack.push(c); // add opening char to stack
        }
       }

       return stack.empty(); // if stack is empty, all pairs valid
    }
};
