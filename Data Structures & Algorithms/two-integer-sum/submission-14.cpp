class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> keys;

       for(int i = 0; i < nums.size(); ++i) {
            int needed = target - nums[i];

            if(keys.find(needed) != keys.end()) {
                return {keys[needed], i};
            }

            keys[nums[i]] = i;
       } 

       return {-1,-1};
    }
};
