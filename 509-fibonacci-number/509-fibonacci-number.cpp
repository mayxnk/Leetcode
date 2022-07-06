class Solution {
public:
    // int helper(int n,vector<int>& a)
    // {
    //     if(n<=1)
    //         return n;
    //     if(a[n]!=-1)
    //         return a[n];
    //     return a[n] = (helper(n-1,a) + helper(n-2,a));
    // }
    int fib(int n) {
        //recusive
        // if(n <=1 )
        //     return n;
        // return fib(n-1) + fib(n-2);
        if(n<=1)
            return n;
        vector<int> a(n+1);
        //helper(n,a);
        a[0] = 0,a[1] = 1;
        for(int i = 2;i<=n;++i)
        {
            a[i] = a[i-1] + a[i-2];
        }
        return a[n];
    }
};