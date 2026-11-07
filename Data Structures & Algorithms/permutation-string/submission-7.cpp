class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) {
            return false;
        }

        vector<int> freq1(26, 0);

        for(char c : s1) {
            freq1[c - 'a']++;
        }

        vector<int> freq2(26, 0);

        for(int l = 0; l < s1.size(); l++) {
            freq2[s2[l] - 'a']++;
        }

        if(freq2 == freq1) {
            return true;
        }

        for(int r = s1.size(); r < s2.size(); ++r) {
            freq2[s2[r - s1.size()] - 'a']--;
            freq2[s2[r] - 'a']++;
            
            if(freq2 == freq1) {
                return true;
            }
        }

        return false;
        
    }
};
