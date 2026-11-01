class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int i : nums) {
            freq[i]++;
        }

        vector<vector<int>> groups(nums.size() + 1);

        for(auto val : freq) {
            groups[val.second].push_back(val.first);
        }

        vector<int> res;

        for(int i = groups.size() - 1; i > 0; --i) {
            for(int j : groups[i]) {
                res.push_back(j);
                if(res.size() == k) {
                    return res;
                }
            }
        }

        return res;
        
    }
};
