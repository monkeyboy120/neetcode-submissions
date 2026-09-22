class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        int res = 0;
        for(int i : nums) {
            if(!mp[i]) {
                mp[i] = mp[i - 1] + mp[i + 1] + 1; // compute new sequence length
                mp[i - mp[i - 1]] = mp[i]; // update left boundary
                mp[i + mp[i + 1]] = mp[i]; // update right boundary
                res = max(res, mp[i]); // update res with longest so far
            }
        }
        return res;
    }
};
