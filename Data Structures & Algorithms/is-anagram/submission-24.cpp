class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> chars;

        for(char c: s) {
            chars[c]++;
        }

        for(char c: t) {
            chars[c]--;
        }

        for(auto count: chars){
            if(count.second != 0) {
                return false;
            }
        }

        return true;
    }
};
