class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<bool>> at,pc;
    int m,n;
    //1 -> pacific ocean
    //2 -> atlantic ocean
    void helper(vector<vector<int>>& heights,int m,int n,int i,int j,vector<int>& temp)
    {
        if(i<=0 or j<=0)
        {
            temp[0] = 1;
        }
        if(i>=m-1 or j>=n-1)
        {
            temp[1] = 2;
        }
        if(temp[0]!=0 || temp[1]!=0)
            return;
        //Now check for all 4 directions using backtracking
        if(heights[i-1][j] <= heights[i][j])
            helper(heights,m,n,i-1,j,temp);
        
        if(heights[i][j+1] <= heights[i][j])
            helper(heights,m,n,i,j+1,temp);
        
        if(heights[i+1][j] <= heights[i][j])
            helper(heights,m,n,i+1,j,temp);
        
        if(heights[i][j-1] <= heights[i][j])
            helper(heights,m,n,i,j-1,temp);
        
        return;
    }
//     void dfs(vector<vector<int>>& heights,vector<vector<bool>>& v,int i,int j)
//     {
//         if(v[i][j])
//             return;
//         v[i][j] = true;
        
//         if(at[i][j] and pc[i][j])
//             ans.push_back(vector<int>{i,j});
        
//         if(i-1 >= 0 and heights[i-1][j] >= heights[i][j]) 
//             dfs(heights,v,i-1,j);
        
//         if(j+1<n and heights[i][j+1] >= heights[i][j])
//              dfs(heights,v,i,j+1);
        
//         if(i+1 < m and heights[i+1][j] >= heights[i][j])
//             dfs(heights,v,i+1,j);
        
//         if(j-1 >= 0 and heights[i][j-1] >= heights[i][j])
//              dfs(heights,v,i,j-1);
        
        

//     }
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
//     {
//         m = heights.size(),n = heights[0].size();
// //         vector<int> temp(2,0);
        
// //         for(int i = 0;i<m;i++)
// //         {
// //             for(int j = 0;j<n;j++)
// //             {
// //                 helper(heights,m,n,i,j,temp);
// //                 if(temp[0]==1 and temp[1] == 2)
// //                 {
// //                     vector<int> v;
// //                     v.push_back(i);
// //                     v.push_back(j);
// //                     ans.push_back(v);
// //                 }
// //                 temp[0] = 0,temp[1] = 0;
// //             }
// //         }
// //         return ans;
//         at = pc = vector<vector<bool>>(m,(vector<bool>(n,false)));
//         for(int i = 0;i<m;i++)
//         {
//             dfs(heights,at,i,0);
//             dfs(heights,at,i,n-1);
//         }
//         for(int i = 0;i<n;i++)
//         {
//             dfs(heights,pc,0,i);
//             dfs(heights,pc,m-1,i);
//         }
//         return ans;
//     }
    vector<vector<bool> > atlantic, pacific;
	//vector<vector<int> > ans;    
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
        if(!size(mat)) return ans;
        m = size(mat), n = size(mat[0]);
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
		// perform dfs from all edge cells (ocean-connected cells)
        for(int i = 0; i < m; i++) dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, n - 1);
        for(int i = 0; i < n; i++) dfs(mat, pacific, 0, i), dfs(mat, atlantic, m - 1, i);             
        return ans;
    }
    void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
        if(visited[i][j]) return;
        visited[i][j] = true;
		// if cell reachable from both the oceans, insert into final answer vector
        if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});    
		// dfs from current cell only if height of next cell is greater
/*⬇️*/  if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
/*⬆️*/  if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
/*➡️*/  if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
/*⬅️*/  if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
    }
};