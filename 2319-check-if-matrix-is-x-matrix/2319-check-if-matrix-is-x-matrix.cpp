class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) 
    {
        int count = 0;
        for(int i = 0;i<grid.size();++i)
        {
            for(int j = 0;j<grid[0].size();++j)
            {
                if(grid[i][j] > 0)
                    ++count;
                if((i+j == grid.size()-1 and grid[i][j] == 0) or (i==j and grid[i][j] == 0))
                    return false;
                if(i!=j and i+j != grid.size()-1 and grid[i][j] != 0)
                    return false;
            }
        }
        // if(count != 2*grid.size())
        //     return false;
        return true;
    }
};