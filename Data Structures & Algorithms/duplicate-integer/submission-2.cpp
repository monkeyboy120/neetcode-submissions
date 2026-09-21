class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(int num : nums) {
            m[num] += 1;
            auto it = m.find(num);
            if(it->second > 1) {
                return true;
            }
        }
        return false;
        
    }
};