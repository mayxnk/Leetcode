class Solution {
public:
    int count = 0;
    bool isPossible(int row,int col,int n,vector<vector<int>> board)
    {
        //For upper column
        for(int i = row-1;i>=0;i--)
            if(board[i][col] == 1)
                return false;
        //For upper left column
        for(int i = row-1,j = col-1;i>=0 && j>=0;j--,i--)
            if(board[i][j] == 1)
                return false;
        //For upper right column
        for(int i = row-1,j = col+1;i>=0 && j<n;j++,i--)
            if(board[i][j] == 1)
                return false;
        return true;
    }
    void nQueenHelper(int n,int row,vector<vector<int>> board)
    {
        if(row == n)
        {
            count++;
            return;
        }
        for(int j = 0;j<n;j++)
        {
            if(isPossible(row,j,n,board))
            {
                board[row][j] = 1;
                nQueenHelper(n,row+1,board);
                board[row][j] = 0;
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<vector<int>> board(n,vector<int>(n,0));
        nQueenHelper(n,0,board);
        
        return count;
    }
};