class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs;

        pairs['}'] = '{';
        pairs[')'] = '(';
        pairs[']'] = '[';

        stack<char> stk;

        for(char c : s) {
            if(pairs.find(c) != pairs.end()) { // is closing
                if(!stk.empty() && stk.top() == pairs[c]) { // if val on stk + is pair
                    stk.pop(); // remove + continue
                } else { // bad pair
                    return false;
                }
            } else {
                stk.push(c); // not closing, add to stack
            }
        }

        return stk.empty(); // if stk empty, all pairs matched
    }

};
