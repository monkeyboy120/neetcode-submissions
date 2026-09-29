class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0; 
        int r = heights.size() - 1;
        int res = 0;

        while (l < r) {
            // area = min height * length
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);

            // move the lower height
            if(heights[l] <= heights[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return res;
        
    }
};
