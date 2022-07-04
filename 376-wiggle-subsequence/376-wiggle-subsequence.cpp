class Solution {
public:
    //1 -> positive
    //0 -> negative
    //Memoization solution
    int dp[1000][2];
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
        memset(dp,0,sizeof(dp));
        //return 1 + max(helper(nums,1,1),helper(nums,0,1));
        
        //DP Approach,Time - O(n),Space - O(n)
        int n = nums.size();
        if(n<=1)
            return n;
        vector<int> prev;
        for(int i = 1;i<n;i++)
        {
            int diff = nums[i] - nums[i-1];
            if(diff!=0)
                prev.push_back(diff);
        }
        int ans = prev.size();
        for(int i = 1;i<prev.size();i++)
        {
            if(prev[i-1]<=0 and prev[i] < 0)
                --ans;
            if(prev[i-1]>=0 and prev[i] > 0)
                --ans;
        }
        return ans + 1;
    }
   
};