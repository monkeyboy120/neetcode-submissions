class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i : nums) {
            res ^= i; // i ^ i = 0, i ^ 0 = i
        }

        return res;
        
    }
};
