class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); ++i) {
            // need negative
            if(nums[i] > 0) { // all remaining positive
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue; // skip duplicates
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    // handle duplicates
                    while(l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                    while(r > l && nums[r] == nums[r + 1]) {
                        --r;
                    }
                } else if (sum > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }

        return res;


    }
};
