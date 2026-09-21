class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       std::unordered_set<int> res;

       for(int i : nums) {
        res.insert(i);
       } 

       if(res.size() != nums.size()) {
            return true;
       }
       return false;
    }
};