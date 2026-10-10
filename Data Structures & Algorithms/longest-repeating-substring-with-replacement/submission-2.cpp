class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;

        int best = 0;

        int l = 0;
        int maxfreq = 0;

        for(int r = 0; r < s.size(); r++) {
            counts[s[r]]++;
            maxfreq = std::max(maxfreq, counts[s[r]]);

            while ((r - l + 1) - maxfreq > k) {
                counts[s[l]]--;
                l++;
            }
            best = std::max(best, r - l + 1);
        } 
        return best;
    }
};
