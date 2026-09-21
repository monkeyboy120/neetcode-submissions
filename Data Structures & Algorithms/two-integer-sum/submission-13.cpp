class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> vals;

        for(int i = 0; i < nums.size(); ++i) {
            int needed = target - nums[i];

            if(vals.find(needed) != vals.end()) {
                return {vals[needed], i};
            }

            vals[nums[i]] = i;
        }

        return {-1, -1};
        
    }
};
