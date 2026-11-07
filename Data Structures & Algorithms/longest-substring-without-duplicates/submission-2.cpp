class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            if(mp.find(s[r]) != mp.end()) { // if we have already seen char
                l = max(mp[s[r]] + 1, l); // jump l to farthest occurence
            }
            mp[s[r]] = r; // update farthest occurence of current char
            res = max(res, r - l + 1); // update longest length
        }

        return res;
    }
};
