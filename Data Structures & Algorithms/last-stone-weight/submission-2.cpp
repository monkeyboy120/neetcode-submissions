class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;

        for(int i : stones) {
            max_heap.push(i);
        }

        while(max_heap.size() > 1) {
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();

            if(y < x) {
                max_heap.push(x - y);
            }

        }

        return max_heap.size() ? max_heap.top() : 0;
    }
};
