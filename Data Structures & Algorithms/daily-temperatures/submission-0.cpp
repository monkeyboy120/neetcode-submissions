class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0); // output vector
        stack<pair<int, int>> stack; // pairs of temp + index

        for(int i = 0; i < temperatures.size(); ++i) {
            int t = temperatures[i];
            while(!stack.empty() && t > stack.top().first) {
                // keep stack in decreasing order
                auto pair = stack.top();
                stack.pop();
                // greater temp
                // pop top + compute how many days passed
                res[pair.second] = i - pair.second; // update output vector 
            }
            stack.push({t, i});
        }
        return res;
    }
};
