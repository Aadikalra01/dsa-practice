class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int m = temperatures.size();
        stack<int>st;
        vector<int>res(m,0);
        for(int i=0;i<m;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int idx=st.top();
                st.pop();
                res[idx]=i-idx;

            }
            st.push(i);
        }
        return res;
        
    }
};