class Solution {
public:
    int minOperations(vector<int>& nums) {
         long long ops = 0;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] <= nums[i-1]){
            long long need = nums[i-1] + 1;
            ops += (need - nums[i]);
            nums[i] = need;
        }
    }
    return ops;
    }
};