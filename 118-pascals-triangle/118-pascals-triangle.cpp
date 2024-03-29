class Solution {
public:
    vector<vector<int>> ans;
    void helper(int num,vector<int> prev,int numRows)
    {
        if(num > numRows)
            return;
        
        vector<int> temp(num);
        temp[0] = 1,temp[num-1] = 1;
        int k = 0;
        for(int i = 1;i<=num-2 and k < prev.size()-1;i++,k++)
           temp[i] = prev[k] + prev[k+1];
        ans.push_back(temp);
        helper(num+1,temp,numRows);
    }
    vector<vector<int>> generate(int numRows) 
    {
//         vector<int> temp{1};
//         ans.push_back(temp);
//         if(numRows==1)
//             return ans;
//         helper(2,temp,numRows);
        
//         return ans;
        //Iterative Approach - DP
        vector<vector<int>> ptri(numRows);
        for(int i = 0;i<numRows;++i)
        {
            ptri[i] = vector<int>(i+1,1);
            for(int j = 1;j<i;++j)
                ptri[i][j] = ptri[i-1][j] + ptri[i-1][j-1];
        }
        return ptri;
    }
};