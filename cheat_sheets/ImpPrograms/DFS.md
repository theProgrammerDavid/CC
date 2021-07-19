### Depth First Search

- [Leetcode Number of Islands](https://leetcode.com/problems/number-of-islands/)

  ```c++
  class Solution {
      private:
      const int dirs[4][2] = {
          {1,0},{0,-1}, {0,1},{-1,0}
      };
      const int LAND = '1';
      const int WATER = '0';
      
      void dfs(vector<vector<char>>& grid, int row, int col){
          int m = grid.size();
          int n = grid[0].size();
          
          // we have to mark the current grid cell as WATER (visited) as a condition to end recursion. Else, we'll get a stack overflow
          grid[row][col] = WATER;
          
          for(auto dir:dirs){
              int r = row + dir[0];
              int c = col + dir[1];
              if(r<0 || c<0 || r>=m || c>=n || grid[r][c] == WATER)continue;
              dfs(grid,r,c);
          }
      }
      
  public:
      int numIslands(vector<vector<char>>& grid) {
          int count = 0;
          int m = grid.size();
          if(m==0)return 0;
          
          int n = grid[0].size();
          
          for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                  if(grid[i][j] == LAND){
                      count++;
                      
                      dfs(grid, i, j);
                     
                  }
              }
          }
          
          return count;
          
      }
  };
  ```

  