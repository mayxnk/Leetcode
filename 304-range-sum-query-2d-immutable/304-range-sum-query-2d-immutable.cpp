class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        //Calculating prefix sum row wise
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<m;j++)
                matrix[i][j] += matrix[i][j-1];
        }
        //Calculating prefix sum column wise
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<m;j++)
                matrix[i][j] += matrix[i-1][j];
        }
        sum = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int totalsum = sum[row2][col2];
        
        int extrasum = (col1!=0 ? sum[row2][col1-1]:0) + 
                       (row1!=0 ? sum[row1-1][col2]:0) -
                       (row1!=0 && col1!=0 ? sum[row1-1][col1-1]:0);
        
        return totalsum - extrasum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */