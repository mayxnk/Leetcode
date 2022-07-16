class Solution {
public:
    //Memoization Approach
    int dp[51][51][52];
    long int mod = 1e9 + 7;
    int helper(int m,int n,int r,int c,int move)
    {
        //Base Case
        if((r==-1 or r == m) and move >= 0)
        {
            return 1;
        }
        if((c == -1 or c == n) and move >= 0)
        {
            return 1;
        }
        //Edge case
        if(move == 0)
            return 0;
        if(dp[r][c][move] != -1)
            return dp[r][c][move];
        //Exploring every Path
        int ans = 0;
        ans = (ans + helper(m,n,r+1,c,move-1))%mod;
        ans = (ans + helper(m,n,r,c+1,move-1))%mod;
        ans = (ans + helper(m,n,r-1,c,move-1))%mod;
        ans = (ans + helper(m,n,r,c-1,move-1))%mod;
        
        return dp[r][c][move] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        memset(dp,-1,sizeof(dp));
        return helper(m,n,startRow,startColumn,maxMove);
        
    }
};