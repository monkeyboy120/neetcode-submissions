class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(string s : strs) {
            vector<int> counts(26, 0);

            for(char c : s) {
                counts[c - 'a']++;
            }

            string key;

            for(int i : counts) {
                key += to_string(i) + "#";
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> res;

        for(auto group : groups) {
            res.push_back(group.second);
        }
        
        return res;
    }
};
