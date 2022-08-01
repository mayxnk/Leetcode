class Solution {
public:
    int dp[101][101];
    int helper(int i,int j,int m,int n)
    {
        if(i==m-1 and j == n-1)
            return 1;
        if(i>m-1 or j>n-1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans1 = helper(i+1,j,m,n);
        int ans2 = helper(i,j+1,m,n);
        return dp[i][j] = ans1 + ans2;
    }
    int uniquePaths(int m, int n) 
    {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,m,n);
    }
};