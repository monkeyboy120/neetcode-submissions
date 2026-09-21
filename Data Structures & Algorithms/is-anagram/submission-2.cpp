class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> chars;
        for(char c : s) {
            chars[c] += 1;
        }
        for(char c : t) {
            chars[c] -= 1;
        }
        for(auto c : chars) {
            if (c.second != 0) {
                return false;
            }
        }
        return true;
    }
};
