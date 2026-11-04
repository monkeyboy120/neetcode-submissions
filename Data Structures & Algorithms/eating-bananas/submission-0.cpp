class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_piles = 0;
        
        for(int i : piles) {
            max_piles = std::max(i, max_piles);
        }

        // k = [1, max_elemtn(piles)]

        int l = 1;
        int r = max_piles;

        int res = r;

        // binary search through
        while(l <= r) {
            int k = (l + r) / 2;

            long long total_time = 0;
            for(int p : piles) {
                total_time += ceil(static_cast<double>(p) / k);
            }

            if(total_time <= h) { // within, record + try smaller speed
                res = k;
                r = k - 1;
            } else { // too small, try larger speed
                l = k + 1;
            }
        }

        return res;

        
    }
};
