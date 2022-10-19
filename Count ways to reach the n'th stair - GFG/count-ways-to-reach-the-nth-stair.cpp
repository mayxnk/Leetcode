//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = 1e9 + 7;
    int helper(int n,vector<int>& dp)
    {
        if(n<=2)
        return n;
        
        if(dp[n] != -1)
        return dp[n];
        
        return dp[n] = (helper(n-1,dp) + helper(n-2,dp))%mod;
    }
    int countWays(int n)
    {
        // your code here
        // if(n<=2)
        // return n;
        
        // return countWays(n-1) + countWays(n-2);
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends