class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;

        int best = 0;

        int l = 0;
        int maxfreq = 0;

        for(int r = 0; r < s.size(); r++) {
            counts[s[r]]++; // increment count at char
            maxfreq = std::max(maxfreq, counts[s[r]]); // set at most common char

            // while window size - most common char > k (aka. while window is valid replaceable substring)
            while ((r - l + 1) - maxfreq > k) {
                counts[s[l]]--; // decrement count at left char (moving window)
                l++; // move window over to make valid again
            }
            best = std::max(best, r - l + 1); // store longest window so far
        } 
        return best;
    }
};
