class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create map, char array is key, string is val
        std::unordered_map<string, vector<string>> res;

        for(auto& str : strs) {
            vector<int> key(26, 0);
            for(char c : str) {
                key[c - 'a']++;
            }
            // C++ doesn't hash vectors
            string new_key;
            for(int i : key) {
                new_key += to_string(i) + "#";
            }

            res[new_key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto it : res) {
            result.push_back(it.second);
        }

        return result;
    }
};
