class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
           int totalDrunk = 0;
    int empty = 0;

    while (numBottles > 0) {
        totalDrunk += numBottles;        // drink all full bottles
        empty += numBottles;             // they become empty

        numBottles = empty / numExchange; // exchange empties for new full bottles
        empty = empty % numExchange;      // leftover empties after exchange
    }

    return totalDrunk;
        
    }
};