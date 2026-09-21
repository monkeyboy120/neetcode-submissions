class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        int zeros = 0;
        // calculate total without 0 while counting 0s
        for(int &i : nums) {
            if(i == 0) {
                zeros++;
            } else {
            total *= i;
            }
        }

        vector<int> res(nums.size(), total);

        // if more than 1 zero, all vals 0
        // if 1 zero, all values other than the 0 are 0
        // if no zeros, just divide for values..
        for(int i = 0; i < nums.size(); ++i) {
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
