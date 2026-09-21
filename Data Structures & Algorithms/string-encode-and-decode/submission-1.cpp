class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string &s : strs) {
            res.append(to_string(s.size())); // encode length of string
            res.push_back('#'); // delimiter
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()) {
            // find len by looking at len + delim
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j-i));

            // str starts after delim
            int start = j + 1;
            // add string of len after delim
            res.push_back(s.substr(start, len));

            // move to next delim
            i = start + len;
        }
        return res;
    }
};
