class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> mp;

        int l = 0;
        int best = 0;

        for (int r = 0; r < s.size(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = std::max(l, mp[s[r]] + 1);
            }
            mp[s[r]] = r;
            best = std::max(best, r - l + 1);
        }

        return best;
    }
};
