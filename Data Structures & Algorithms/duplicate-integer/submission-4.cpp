class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set<int> a;
       for(int num : nums) {
            if(a.find(num) != a.end()) {
                return true;
            }
            else {
            a.insert(num);
            }
       } 
        return false;
    }
};