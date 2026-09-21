class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       std::set<int> vals;

       for(int num : nums) {
        vals.insert(num);
       } 

       return vals.size() != nums.size();
    }
};