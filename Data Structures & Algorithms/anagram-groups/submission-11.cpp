class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

       for(string &s : strs) {
        vector<int> hashes(26,0);
        for(char c : s) {
           hashes[c - 'a']++;
        }
        string key;
        for(int i : hashes) {
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
