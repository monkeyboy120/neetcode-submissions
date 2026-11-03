class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos;

        for(int i = 0; i < nums.size(); ++i) {
            int needed = target - nums[i];

            if(pos.find(needed) != pos.end()) {
                return {pos[needed], i};
            }

            pos[nums[i]] = i;
        }    

        return {-1, -1};
    }
};
