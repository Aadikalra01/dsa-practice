class Solution {
public:
    int dp[205][2005];
    bool solve(int i,int target,vector<int> & nums){
        if(target==0) return true;
        if(i==nums.size() ) return false;
        if(target<0) return false;
        if(dp[i][target]!= -1) return dp[i][target];
        bool not_take= solve(i+1,target,nums);
        bool take= false;
        if(target>=nums[i]){
            take= solve(i+1,target-nums[i],nums);
        }
        return dp[i][target]=take || not_take;

    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2) return false;

        int target=sum/2;
        memset(dp,-1,sizeof(dp));
        return solve(0,target,nums);
    }
};