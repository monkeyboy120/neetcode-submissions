class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0;
        int minPrice = prices[0];

        for(int p : prices) {
            minPrice = min(minPrice, p);
            maxPrice = max(p - minPrice, maxPrice);
        }

        return maxPrice;
        
    }
};
