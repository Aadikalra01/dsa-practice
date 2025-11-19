class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;

    for (int price : prices) {
        buy1 = max(buy1, -price);          // Best after buying 1st time
        sell1 = max(sell1, buy1 + price);  // Best after selling 1st time
        buy2 = max(buy2, sell1 - price);   // Best after buying 2nd time
        sell2 = max(sell2, buy2 + price);  // Best after selling 2nd time
    }

    return sell2;
    }
};