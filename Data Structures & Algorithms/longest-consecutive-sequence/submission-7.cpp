class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> mp;

        int best = 0;

        for(int num : nums) {
            if(!mp[num]) { // not in
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];
                best = std::max(mp[num], best);
            }
        }

        return best;
        
    }
};
