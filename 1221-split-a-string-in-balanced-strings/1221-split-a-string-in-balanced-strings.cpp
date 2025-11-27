class Solution {
public:
    int balancedStringSplit(string s) {
        int balance =0;
        int answer=0;
        for(int c =0;c<s.size();c++){
            if(s[c]=='R'){
                balance++;
            }
            else{
                balance--;
               
            }
             if(balance==0) answer++;
            
        }
        return answer;
    }
};