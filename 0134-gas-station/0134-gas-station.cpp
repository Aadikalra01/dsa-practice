class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg=0,tc=0;
        for(int val:gas){
            tg+=val;
        }
        for(int val:cost){
            tc+=val;
        }
        if(tg<tc) return -1;
        int cur=0,start=0;
        for(int i =0;i<gas.size();i++){
            cur+=gas[i]-cost[i];
            if(cur<0){
                start=i+1;
                cur=0;
            }

        }
        return start;
        
    }
};