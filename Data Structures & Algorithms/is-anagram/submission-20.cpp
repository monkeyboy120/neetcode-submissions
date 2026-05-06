class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> chars;

        for(char c: s) {
            chars[c]++;
        }

        for(char c: t) {
            chars[c]--;
        }

        for(auto counts : chars) {
            if(counts.second != 0) {
                return false;
            }
        }

        return true;
        
    }
};
