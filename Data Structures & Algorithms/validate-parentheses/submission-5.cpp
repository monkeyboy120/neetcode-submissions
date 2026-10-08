class Solution {
   public:
    bool isValid(string s) {
        std::stack<char> stk;

        std::unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for(char c : s) {
            if(pairs.find(c) != pairs.end()) { // if end char
                if(!stk.empty() && stk.top() == pairs[c]) {
                    stk.pop(); // good pair, remove
                } else {
                    return false;
                }
            } else {
                stk.push(c); // add opening to stack
            }
        }

        return stk.empty();
    }
};
