class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the vector in ascending order
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        // need negative to add to 0
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) break;  // all remaining are positive
            if (i > 0 && nums[i] == nums[i - 1]) { // skip duplicates`
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            // use two pointer + sorted vec
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {  // greater than 0 need smaller
                    --r;
                } else if (sum < 0) {  // less than 0 need bigger
                    ++l;
                } else {  // if 0 add to res
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    // handle duplicates
                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                    while (r > l && nums[r] == nums[r + 1]) {
                        --r;
                    }
                }
            }
        }
        return res;
    }
};
