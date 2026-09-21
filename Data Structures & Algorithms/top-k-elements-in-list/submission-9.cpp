class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for(int i : nums) {
            counts[i]++;
        }
        
        vector<vector<int>> groups(nums.size() + 1);

        for(auto count : counts) {
            groups[count.second].push_back(count.first);
        }

        vector<int> res;
        for(int i = groups.size() - 1;i > 0; --i) {
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
