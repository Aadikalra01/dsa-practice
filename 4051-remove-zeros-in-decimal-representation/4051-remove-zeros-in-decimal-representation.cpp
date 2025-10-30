class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string result="";
        for(char ch :s){
            if(ch!='0') result+=ch;
        }
        if(result.empty()){
            return 0;
        }
        return stol(result);
        
    }
};