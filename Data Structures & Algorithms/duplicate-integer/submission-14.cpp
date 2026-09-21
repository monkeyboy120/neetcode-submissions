class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> vals;

        for(int i : nums) {
            vals.insert(i);
        }

        if(vals.size() < nums.size()) {
            return true;
        }

        return false;
        
    }
};