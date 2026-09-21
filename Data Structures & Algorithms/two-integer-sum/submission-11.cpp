class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> lookup; // key = diff, val = index

        for(int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            
            // now check if already seen what it needs
            auto it = lookup.find(diff);

            if(it != lookup.end()) {
                return {lookup[diff], i}; // lookup comes first as it was seen before this
            }
            
            // save to map after, if before duplicates for 50% of target
            lookup[nums[i]] = i;
        }

        return {-1, -1};
    }
};
