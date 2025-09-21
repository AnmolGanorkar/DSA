class Solution {
public:
int fib(int n) {
    int fn=0;
    int f0=0;
    int f1=1;
    if(n<=1)
    {
        return n;
    }
        for(int i=1;i<n;i++)
        {
            fn=f0+f1;
            f0=f1;
            f1=fn;
        }
        return fn;
    }
};