class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int best = 0;

        while(l < r) {
            int len = r - l;
            int area = min(heights[l], heights[r]) * len;
            best = max(area, best);

            // just move lower height pointer;
            if(heights[l] <= heights[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return best;
        
    }
};
