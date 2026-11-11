class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        int bestSum = nums[0];

        int runningSum = 0;

        for(int i : nums) {
            runningSum = max(runningSum + i, i);
            bestSum = max(runningSum, bestSum);
        }

        return bestSum;
    }
};
