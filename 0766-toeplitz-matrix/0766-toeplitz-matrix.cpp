class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0;i<matrix.size();++i)
        {
            for(int j = 1;j<matrix[i].size();++j)
                if(i-1>=0 and j-1>=0 and matrix[i][j] != matrix[i-1][j-1])
                    return false;
        }
        return true;
    }
};