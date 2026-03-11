class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string ans="";
        while(n>0){
            if(n%2==0) ans+='0';
            else ans+='1';
            n=n/2;

        }
        reverse(ans.begin(),ans.end());
        for(char &c:ans){
            if(c=='0')c='1';
            else c='0';

        }
        int result=0;
        for(char c:ans){
            result= result*2 +(c-'0');
        }
        return result;



        
    }
};