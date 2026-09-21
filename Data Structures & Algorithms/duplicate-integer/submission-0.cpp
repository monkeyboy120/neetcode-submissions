class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> values;
        for(int i : nums) {
            values[i] += 1;
        }
        for(auto i : values) {
            if(i.second > 1) {
                return true;
            }
        }
        return false;
    }
};