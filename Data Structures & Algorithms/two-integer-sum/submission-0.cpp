class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairs;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (pairs.count(diff)) {
                return {pairs[diff], i}; 
            }
            pairs[nums[i]] = i;
        }
        return {}; 
    }
};