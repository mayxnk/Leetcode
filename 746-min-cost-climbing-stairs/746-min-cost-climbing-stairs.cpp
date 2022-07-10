class Solution {
public:
    
    int helper(vector<int> &cost,int i,int sum,vector<int>& dp)
    {
        if(i>=cost.size()-2)
            return cost[i];
        
        if(dp[i]!=-1)
            return dp[i];
        int a = helper(cost,i+1,cost[i+1] + sum,dp);
        
        int b = helper(cost,i+2,cost[i+2] + sum,dp);
        
        return dp[i] = min(a,b) + cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> dp(cost.size()+1,-1);
        return min(helper(cost,0,cost[0],dp),helper(cost,1,cost[1],dp));
    }
};