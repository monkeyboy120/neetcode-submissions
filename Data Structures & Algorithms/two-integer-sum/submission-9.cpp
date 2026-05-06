class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> tracker; // tracker<val, index>

        for(int i = 0; i < nums.size(); ++i) {
            int wanted = target - nums[i];
            // if not found, add to map
            if(tracker.find(wanted) == tracker.end()){
                tracker[nums[i]] = i;
            } else {
                // return map value first for smaller index, as it has to appear before
                return {tracker[wanted], i};
            }
        }

        return {-1, -1}; // should never reach
        
    }
};
