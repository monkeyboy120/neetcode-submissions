class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;

        int l = 0;
        int r = heights.size() - 1;

        while(l < r) {
            int area = (r - l) * std::min(heights[l], heights[r]);
            max = std::max(area, max);

            if(heights[r] < heights[l]) {
                r--;
            } else {
                l++;
            }
        }
       return max; 
    }
};
