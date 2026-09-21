class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for(int num : nums) {
            s.insert(num);
        }

        return s.size() != nums.size();
    }
};