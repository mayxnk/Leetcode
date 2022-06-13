class Solution {
public:
    //Recursive Approach - TLE,Memoization
    int helper(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& ans)
    {
        if(i == triangle.size())
            return 0;
        if(ans[i][j] != -1)
            return ans[i][j];
        int sum1 = helper(triangle,i+1,j,ans);
        
        int sum2 = helper(triangle,i+1,j+1,ans);
        
        // = min(sum1,sum2) + triangle[i][j];
        
        return ans[i][j] = min(sum1,sum2) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if(triangle.size()==1 && triangle[0].size()==1)
            return triangle[0][0];
        int n = triangle.size();
        vector<vector<int>> ans(n, vector<int>(n,-1));
        return helper(triangle,0,0,ans);
    }
};