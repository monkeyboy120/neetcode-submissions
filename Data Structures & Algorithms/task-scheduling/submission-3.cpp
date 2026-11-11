class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> max_heap;

        for(int val : count) {
            if(val > 0) {
                max_heap.push(val);
            }
        }
        

        int time = 0;
        queue<pair<int, int>> q; // {remaining count after tunning, next avail time}

        while(!max_heap.empty() || !q.empty()) { // while still have things to process
            time++;

            if(!max_heap.empty()) {
                int max_f = max_heap.top();
                max_heap.pop();
                max_f--;
                if(max_f > 0) { // if still remaining, put on cooldown
                    q.push({max_f, time + n}); // can be used after n units
                }
            }

            if(q.front().second == time) {
                auto val = q.front();
                q.pop();
                max_heap.push(val.first);
            }
        }

        return time;
    }
};
