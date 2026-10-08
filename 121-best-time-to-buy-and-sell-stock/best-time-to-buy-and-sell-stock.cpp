class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minCost = prices[0];   // cheapest buy price so far
        int profit  = 0;           // best profit so far

        for (int i = 1; i < prices.size(); i++) {
            profit  = max(profit, prices[i] - minCost); // sell today?
            minCost = min(minCost, prices[i]);          // cheaper buy found?
        }
        return profit;
    }
};