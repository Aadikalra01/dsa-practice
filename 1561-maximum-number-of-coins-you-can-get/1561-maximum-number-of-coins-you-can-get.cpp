class Solution {
public:
    int maxCoins(vector<int>& piles) {
           sort(piles.begin(),piles.end());
        int n = piles.size();
        int you= n-2;
        int bob=0;
        int ans=0;
        while(bob<you){
            ans+=piles[you];
            you = you-2;
            bob+=1;
        }
        return ans;


    }
};