class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;

        for(int num :  nums) {
            if(!mp[num]) { // skip if already in
                mp[num] = mp[num - 1] + mp[num + 1] + 1; // extend with length of subsequence on both sides
                // update boundary lengths, num - mp[num-1] = farthest left in subsequence
                // left boundary
                mp[num - mp[num - 1]] = mp[num];
                // right boundary
                mp[num +mp[num + 1]] = mp[num];
                res = max(res, mp[num]);
            }

        }
        return res;
    }
};
