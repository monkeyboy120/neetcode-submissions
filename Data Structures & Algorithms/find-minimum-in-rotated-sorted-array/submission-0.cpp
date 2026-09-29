class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) { // minimum is in left
                r = mid;
            } else { // min is in right
                l = mid +1;
            }
        }

        return nums[l];
        
    }
};
