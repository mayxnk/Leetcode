class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<vector<int>> ans(rowIndex+1);
        vector<int> t(rowIndex+1);
        for(int i = 0;i<=rowIndex;++i)
        {
            ans[i] = vector<int>(i+1,1);
            for(int j = 1;j<i;j++)
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
        int k = 0;
        for(int i = 0;i<=rowIndex;++i)
            t[k++] = ans[rowIndex][i];
        return t;
    }
};