class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int zeros = 0;
        // calc total + zeros
        for(const int& i : nums) {
            if(i == 0) {
                zeros++;
            } else {
                total *= i;
            }
        }

        vector<int> res(nums.size(), total);

        // if more than 1 zero, all vals zero
        // if 1 zero, all vals other than 0 are 0
        // if no zeros; divide all vals by nums[i]
        for(int i =0; i < nums.size(); ++i) {
            if (zeros > 1) {
                res[i] = 0;
            } else if (zeros == 1) {
                if(nums[i] == 0) {
                    res[i] = total;
                } else {
                    res[i] = 0;
                }
            } else {
                res[i] = total / nums[i];
            }
        }

        return res;
    }
};
