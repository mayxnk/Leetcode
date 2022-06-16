class Solution {
public:
    bool check(string s)
    {
        string temp = s;
        reverse(s.begin(),s.end());
        return s == temp;
    }
    void helper(string s,string& ans,string temp,int j,int& len)
    {
        if(j == s.size())
            return;
        temp = temp + s[j];
        if(check(temp) && temp.size() > len)
        {
            ans = temp;
            len = temp.size();
        }
        helper(s,ans,temp,j+1,len);
    }
    string longestPalindrome(string s) 
    {
        int len = 1;
        string temp = "",ans = "";
        // for(int i = 0;i<s.size();i++)
        // {
        //     temp = s[i];
        //     for(int j = i+1;j<s.size();j++)
        //     {
        //         if(check(temp) && temp.size() > len)
        //         {
        //             len = temp.size();
        //             ans = temp;
        //         }
        //         temp = temp + s[j];
        //     }
        // }
        //Recusive Approach - TLE
        /*for(int i = 0;i<s.size();++i)
        {
            helper(s,ans,"",i,len);
        }
        */
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //as single character is Pal
        for(int i = 0;i<n;++i)
            dp[i][i] = 1;
        int start = 0,end = 1;
        for(int i = 0;i<n-1;i++)
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                start = i;
                end = 2;
            }
        
        for(int i = 2;i<n;i++)
        {
            for(int j = 0;j<n-i;j++)
            {
                int left = j,right = i + j;
                if(dp[left+1][right-1] == 1 and s[left] == s[right])
                {
                    dp[left][right] = 1;
                    start = j;
                    end = i+1;
                }
            } 
        }
        ans = s.substr(start,end);
        return ans;
    }
};