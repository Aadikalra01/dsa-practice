class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int &x : nums) x = abs(x);

        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i =0;
        int j =n-1;
        vector<int>result(n);

        for(int k=0;k<n;k++){
            if(k%2==0){
                result[k]=nums[j--];

            }
            else{
                result[k]=nums[i++];
            }

        }
        long long score=0;
        for(int k=0;k<n;k++){
            long long val = 1ll*result[k]*result[k];
            if(k%2==0){
                score+=val;
            }
            else score-=val;

        }
        return score;
    }
};