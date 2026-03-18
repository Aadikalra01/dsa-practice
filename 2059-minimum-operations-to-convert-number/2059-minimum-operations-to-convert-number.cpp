class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<pair<int,int>>q;
        vector<int>vis(1001,0);
        q.push({start,0});
        vis[start]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int val=it.first;
            int steps=it.second;

            for(int x:nums){
                vector<int>nextvals{
                    val+x,
                    val-x,
                    val^x
                };
                for(int newVal:nextvals){
                    if(newVal==goal) return steps+1;
                    if(newVal>=0 && newVal <=1000 && !vis[newVal]){
                        vis[newVal]=1;
                        q.push({newVal,steps+1});
                    }
                }
            }
        }
        return -1;

        
    }
};