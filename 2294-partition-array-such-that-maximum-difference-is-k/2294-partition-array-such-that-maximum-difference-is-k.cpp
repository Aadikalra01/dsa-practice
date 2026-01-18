class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min =nums[0];
        int max = nums[0];
        int sub=1;
        for(int i =1;i<nums.size();i++){
            int max= nums[i];
            if((max-min)>k){
                sub+=1;
                min=nums[i];
            }
        }
        return sub;
    }
};