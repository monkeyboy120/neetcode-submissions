class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> chars;

        for(char c : s) {
            chars[c]++;
        }

        for(char c : t) {
            chars[c]--;
        }

        for(auto it : chars) {
            if(it.second != 0) {
                return false;
            }
        }

        return true;
        
    }
};
