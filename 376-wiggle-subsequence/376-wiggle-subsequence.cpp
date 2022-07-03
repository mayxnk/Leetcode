class Solution {
public:
    //1 -> positive
    //0 -> negative
    //Memoization solution
    int dp[1001][2];
    int helper(vector<int>& nums,int sign,int i)
    {
        if(i == nums.size())
            return 0;
        if(dp[i][sign] != -1)
            return dp[i][sign];
        int ans1 = INT_MIN;
        if(sign)
        {
            if(nums[i] > nums[i-1])
                ans1 = max(helper(nums,!sign,i+1) + 1,ans1);
            ans1 = max(helper(nums,sign,i+1),ans1);
        }
        else
        {
            if(nums[i] < nums[i-1])
                ans1 = max(helper(nums,!sign,i+1) + 1,ans1);
            ans1 = max(helper(nums,sign,i+1),ans1);
        }
        
        return dp[i][sign] = ans1;
    }
    int wiggleMaxLength(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return 1 + max(helper(nums,1,1),helper(nums,0,1));
    }
};