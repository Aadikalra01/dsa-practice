class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>st;
        
        for(int i =0;i<heights.size()-1;i++){
            int dif= heights[i+1]-heights[i];
            if(dif<=0) continue;
            bricks-=dif;
            st.push(dif);
            if(bricks<0){
                if(ladders==0) return i ;
                bricks+=st.top();
                ladders--;
                st.pop();
            }
        }
        return heights.size()-1;
    }
};