class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l < r) {
            int m = l + (r - l) / 2;
            if(nums[m] < nums[r]) { // min in left half
                r = m;
            } else { // min in right half
                l = m + 1;
            }
        }

        // l has idx of min / pivot

        // one side of array is nums[0, l - 1], nums[l, nums.size()]
        int res = binary_search(nums, target, 0, l - 1);
        if(res != -1) {
            return res;
        }

        res = binary_search(nums, target, l, nums.size() - 1);
        return res;
    }

    int binary_search(vector<int> nums, int target, int l, int r) {
        int left = l;
        int right = r;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
