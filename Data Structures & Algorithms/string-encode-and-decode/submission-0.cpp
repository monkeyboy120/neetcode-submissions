class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string &s : strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));

            int start = j + 1;
            res.push_back(s.substr(start, len));

            // move to next str 
            i =  start + len;
        }
        return res;
    }
};
