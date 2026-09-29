class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int best = 0;

        while (r < prices.size()) {
            if(prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                best = max(best, profit);
            } else { // cheaper buy price
                l = r;
            }
            r++;
        }

        return best;
    }
};
