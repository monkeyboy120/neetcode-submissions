class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) break; // can't be any more pairs
            if(i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates

            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if(sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else { // add to res and skip duplicates
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while(r > l && nums[r] == nums[r + 1]) {
                        r--;
                    } 

                }
            }
        }
        return res;
    }
};
