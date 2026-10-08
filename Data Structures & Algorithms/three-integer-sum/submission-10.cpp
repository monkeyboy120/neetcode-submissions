class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the vector
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); ++i) {
            // check if negative
            if (nums[i] > 0) {
                break;  // all remaining are positive
            }

            // skip over duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int needed = -nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum > needed) {
                    right--;
                } else if (sum < needed) {
                    left++;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    right--;
                    left++;
                    // skip over duplicates
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (right > left && nums[right + 1] == nums[right]) {
                        right--;
                    }
                }
            }
        }

        return res;
    }
};
