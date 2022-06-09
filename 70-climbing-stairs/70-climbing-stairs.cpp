class Solution {
public:
    int climbStairs(int n) 
    {
        if(n==1 || n==2)
            return n;
        if(n==3)
            return 3;
        int *ans = new int[n+1];
        for(int i = 0;i<n+1;i++)
            ans[i] = -1;
        
        ans[1] = 1,ans[2] = 2;
        for(int i = 3;i<n+1;i++)
        {
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }
};