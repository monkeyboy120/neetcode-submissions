class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count freq of each int
        unordered_map<int, int> counts;
        // 
        vector<vector<int>> freq(nums.size() + 1);

        // loop through list and get counts
        for (int i : nums) {
            counts[i] = counts[i] + 1;
        }

        // put into buckets (vector) based on freq
        for (const auto& val : counts) {
            freq[val.second].push_back(val.first);
        }

        // most freq at end so reverse through
        vector<int> result;
        for (int i = freq.size() - 1; i > 0; --i) {
            // grab all the values at that level
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
