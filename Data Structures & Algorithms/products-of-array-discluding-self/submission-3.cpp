class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numZ = 0;
        int product = 1;

        for(int i : nums) {
            if(i == 0) {
                numZ++;
            } else {
                product *= i;
            }
        }

        vector<int> res(nums.size(), 0);

        if(numZ > 1) {
            return res;
        }

        for(int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            if(numZ == 1) {
                if(curr == 0) {
                    res[i] = product;
                } else {
                    res[i] = 0;
                }
            }
            if(numZ == 0) {
                res[i] = product / nums[i];
            }
        }

        return res;
    }
};
