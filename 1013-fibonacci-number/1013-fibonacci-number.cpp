class Solution {
public:
    int fib(int n) {
        int a =0;
        int b =1;
        if(n==0) return 0;
        if(n<=2) return a+b;
        for(int i =1;i<n;i++){
            int curr = a+b;
            a=b;
            b=curr;
        }
        return b;
        
    }
};