class Solution {
public:
    int maxArea(vector<int>& heights) {
        int best = 0;

        int l = 0;
        int r = heights.size() - 1;

        while( l < r) { 
            int area = (r - l) * std::min(heights[l], heights[r]);
            best = std::max(area, best);

            if(heights[l] <= heights[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return best;
        
    }
};
