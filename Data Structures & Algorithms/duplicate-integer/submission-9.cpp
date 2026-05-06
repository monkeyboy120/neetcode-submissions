class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> unique;
        for (int i : nums) {
            unique.insert(i);
        }

        return unique.size() != nums.size();
    }
};