class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> vals;

        

        for(string& str : strs) {
            vector<int> a(26, 0);
            for(char c : str) {
                a[c - 'a']++;
            }
            string key;
            for(int i : a) {
                key += to_string(i) + "#";
            }
            vals[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto val : vals) {
            vector<string> in;
            for(string str : val.second) {
                in.push_back(str);
            }
            result.push_back(in);
        }

        return result;
    }
};
