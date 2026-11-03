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

        reverse(groups.begin(), groups.end());

        for(auto group : groups) {
            for(int i : group) {
                res.push_back(i);
                if(res.size() == k) {
                    return res;
                }
            }
        }

        return res;
        
    }
};
