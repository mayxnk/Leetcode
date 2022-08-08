// class Solution {
// public:
//     int helper(vector<int> nums,int prev,int curr,vector<vector<int>> dp)
//     {
//         if(curr == nums.size())
//             return 0;
        
//         if(prev!= -1 and dp[prev][curr] != -1)
//             return dp[prev][curr];
//         int first = 0;
//         if(prev == -1 || nums[prev] < nums[curr])
//             first = helper(nums,curr,curr+1,dp) + 1;
//         int sec = helper(nums,prev,curr+1,dp);
        
//         if(prev!=-1)
//         return dp[prev][curr] = max(first,sec);
//         else
//             return max(first,sec);
       
//     }
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
//         return helper(nums,-1,0,dp);
//     }
// };
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int k=nums.size();
        int **ans = new int*[k+1];
	    for(int i = 0; i <= k; i++) {
		    ans[i] = new int[k+1];
		    for(int j = 0; j <= k; j++) {
		    	ans[i][j] = -1;
		    }
	    }
        return lis(-1,0,nums,ans);
    }
    int lis(int prev,int curr,vector<int>& arr,int **dp){
        if(curr==arr.size()){
            return 0;
        } 
        if(prev!=-1 && dp[prev][curr]!=-1){
            return dp[prev][curr];
        }
        int first=0;
        if(prev==-1 || arr[prev]<arr[curr]){
            first=1+lis(curr,curr+1,arr,dp);
        }
        int sec=lis(prev,curr+1,arr,dp);
        if(prev!=-1){
            return dp[prev][curr]=max(first,sec);
        }else
            return max(first,sec);
    }
};