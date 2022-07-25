class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //Binary Search Approach : T - O(n+m)
        if(matrix.size() == 0)
            return false;
        int row = matrix.size(),col = matrix[0].size();
        int i = 0,j = col - 1;
        while(i < row and j >=0)
        {
            int element = matrix[i][j];
            if(element == target)
                return true;
            else if(element > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};