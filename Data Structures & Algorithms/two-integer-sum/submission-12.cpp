class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> vals;

        for(int i = 0; i < nums.size(); ++i) {
            int needed = target - nums[i];

            auto res = vals.find(needed); // search for result, if not found end
            if(res != vals.end()) {
                return {vals[needed], i};
            } 

            vals[nums[i]] = i;
        }

        return {-1, -1};
        
    }
};
