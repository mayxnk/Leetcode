// #include<queue>
// class Solution {
// public:
//     int BFS(vector<vector<char>>& grid,int v,int sv,bool *visited)
//     {
//     visited[sv] = true;
//     queue<int> curr;
    
//     curr.push(sv);
//     while(curr.size()!=0)
//     {
//         int cv = curr.front();
//         curr.pop();
        
//         for(int i = 0;i<v;i++)
//         {
//             if(grid[cv][i] == 1 && !visited[i])
//             {
//                 visited[i] = true;
//                 curr.push(i);
//             }
//         }
//     }
//     return 1;
//    }
//     int numIslands(vector<vector<char>>& grid) 
//     {
//          int n = grid.size()*grid[0].size();
//          bool *visited = new bool[n];
//          for(int i = 0;i<n;i++) visited[i] = false;
    
//           int count,tCount = 0;
//           for(int i = 0;i<n;i++)
//          {
//             if(!visited[i])
//                 count = BFS(grid,n,i,visited);
//             tCount += count;
//             count = 0;
//          }
//           return tCount;
//     }
// };
class Solution {
public:
    int DR[4]={1, 0, -1, 0};
    int DC[4]={0, -1, 0, 1};
    
    bool valid_index(int i, int j, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        return true;
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j]='0';
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0; k<4; k++) {
                int ci=DR[k]+i;
                int cj=DC[k]+j;
                if(!valid_index(ci, cj, grid))
                    continue;
                if(grid[ci][cj]=='1') {
                    q.push({ci, cj});
                    grid[ci][cj]='0';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int no_of_islands=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    no_of_islands++;
                    bfs(i, j, grid);
                }
            }
        }
        return no_of_islands;
    }
};