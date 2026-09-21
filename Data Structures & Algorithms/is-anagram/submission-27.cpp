class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> vals;

        for(char c : s) {
            vals[c]++;
        }

        for(char c : t) {
            vals[c]--;
        }

        for(auto val : vals) {
            if(val.second != 0) {
                return false;
            }
        }

        return true;
    }
};
