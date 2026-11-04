class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seq;

        int max = 0;

        for (int i : nums) {
            if (!seq[i]) {
                seq[i] = seq[i + 1] + seq[i - 1] + 1;  // update based on longest left and right
                seq[i - seq[i - 1]] = seq[i];          // set left most to update length
                seq[i + seq[i + 1]] = seq[i];          // update right most length
                max = std::max(max, seq[i]);
            }
        }

        return max;
    }
};