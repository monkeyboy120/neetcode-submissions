class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string s : strs) {
            vector<int> hash(26, 0);

            for(char c : s) {
                hash[c - 'a']++;
            }

            string key;

            for(int i : hash) {
                key += to_string(i) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;

        for(auto group : mp) {
            res.push_back(group.second);
        }

        return res;
        
    }
};
