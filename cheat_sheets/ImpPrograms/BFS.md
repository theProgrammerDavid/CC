### Breadth First Search

- [Leetcode Number of Islands](https://leetcode.com/problems/number-of-islands/)

  ```c++
  class Solution{
      private:
      const int dirs[4][2] = {
          {1,0}, {-1,0}, {0,1}, {0,-1}
      }
      const int LAND = '1';
      const int WATER = '0';
      
      public: 
      
      int numIslands(vector<vector<char>>& grid){
          int count = 0;
          int m = grid.size();
          
          if(m==0)return 0;
          //empty array
          
          int n = grid[0].size();
          
          for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                  // we start iterating through the grid
                  if(grid[i][j] == LAND){
                      
                      count++;
                      //we increment the counter now rather than later since there could be only 1 large island and if incremented later, might return 0
                      
                      grid[i][j] = WATER;
                      //we mark it as WATER (visited) for later
                      
                      queue<pair<int,int>> q;
                      q.push({i,j});
                      
                      while(!q.empty()){
                          auto t = q.front();
                          q.pop();
                          // Java has q.poll() which combines both front and pop
                          int row = t.first;
                          int col = t.second;
                          
                          //you could use 4 if statements, but the loop is cleaner
                          for(auto dir:dirs){
                              int r = row + dir[0];
                              int c = row + dir[1];
                              
                              //edge cases check
                              if(r<0 || c<0 || r>=m || c>=n ||
                                grid[r][c] == WATER
                                )
                                  continue;
                              
                              grid[r][c] = WATER;
                              q.push({r,c});
                          }
                      }
                  }
              }
          }
          return count;
      }
  }
  ```

  