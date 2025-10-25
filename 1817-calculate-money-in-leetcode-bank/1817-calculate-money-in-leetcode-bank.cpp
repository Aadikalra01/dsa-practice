class Solution {
public:
    int totalMoney(int n) {
         int weeks = n / 7;
        int days = n % 7;
        
        
        int totalWeeks = weeks * 28 + (weeks * (weeks - 1) / 2) * 7;
        
        
        int start = weeks + 1;
        int totalDays = days * (2 * start + (days - 1)) / 2;
        
        return totalWeeks + totalDays;
    }
};