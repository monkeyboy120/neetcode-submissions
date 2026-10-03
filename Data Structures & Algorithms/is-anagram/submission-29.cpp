class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counts;

        for(char c : s) {
            counts[c]++;
        }

        for(char c : t) {
            counts[c]--;
        }

        for(auto count : counts) {
            if(count.second != 0) {
                return false;
            }
        }

        return true;
        
    }
};
