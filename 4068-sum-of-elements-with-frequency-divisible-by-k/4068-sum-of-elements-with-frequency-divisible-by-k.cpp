class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int sum =0;
        for(auto it:mp){
            if(it.second%k==0){
                for(int i =0;i<it.second;i++){
                     sum+=it.first;
                }
               
            }
        }
        return sum ;
    }
};