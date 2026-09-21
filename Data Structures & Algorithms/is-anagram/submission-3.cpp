class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> a;
        for(char ch : s) {
            a[ch]++;
        }

        for(char ch : t) {
            a[ch]--;
        }

        for(auto pair : a) {
            if(pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};
