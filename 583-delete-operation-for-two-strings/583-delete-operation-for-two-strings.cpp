class Solution {
public:
    //Recursive Approach - Time - O(2 ^ max(word1.size,word2.size))
    int findLCS(string s1,string s2,int m,int n,vector<vector<int>>& ans)
    {
        //Base Case
        if(m < 0 || n < 0)
            return 0;
        if(ans[m][n] != -1)
            return ans[m][n];
        if(s1[m] == s2[n])
            return ans[m][n] =  1 + findLCS(s1,s2,m-1,n-1,ans);
        return ans[m][n] = max(findLCS(s1,s2,m-1,n,ans),findLCS(s1,s2,m,n-1,ans));
    }
    int minDistance(string word1, string word2) 
    {
        int m = word1.size(),n = word2.size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int lcs = findLCS(word1,word2,m-1,n-1,ans);
        return (m - lcs + n - lcs);
    }
};