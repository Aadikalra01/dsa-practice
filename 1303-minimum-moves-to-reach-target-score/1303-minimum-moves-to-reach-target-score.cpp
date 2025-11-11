class Solution {
public:
    int minMoves(int target, int maxDoubles) {
int cnt = 0;
while (target > 1) {
    if (maxDoubles > 0) {
        if (target % 2 == 0) {
            target /= 2;
            maxDoubles--;
        } else {
            target -= 1;
        }
    } else {
        cnt += target - 1;  
        break;
    }
    cnt++;
}
return cnt;
    }
};