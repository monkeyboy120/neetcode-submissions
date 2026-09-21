class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;

        std::unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char c : s) {
            if(pairs.count(c)) { // if end char
                if(!stack.empty() && stack.top() == pairs[c]) {
                    stack.pop(); // matching open + close pair
                }
                else {
                    return false;
                }
            }
            else {
                stack.push(c); // opening char
            }
        }
        
        return stack.empty(); // if all chars popped off all open close paired
    }
};
