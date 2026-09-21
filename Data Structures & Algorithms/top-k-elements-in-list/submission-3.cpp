class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count freq of each int
        unordered_map<int, int> counts;

        // get counts
        for(int i : nums) {
            counts[i]++;
        }

        // vector of buckets
        vector<vector<int>> freq(nums.size() + 1);

        // group by freq
        for (auto val : counts) {
            freq[val.second].push_back(val.first);
        }

        // most freq will be in back
        vector<int> result;
        for(int i = freq.size() - 1; i > 0; --i) {
            // get all values at each level
            for(int j : freq[i]) {
                result.push_back(j);
                if(result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
