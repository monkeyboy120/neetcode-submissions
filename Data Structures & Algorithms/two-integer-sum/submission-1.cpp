class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> a;
        for(int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if(a.find(nums[i]) != a.end()) {
                return {a[nums[i]], i};
            }
            a[diff] = i;
        }
        return {0,0};
    }
};
