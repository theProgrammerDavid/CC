import java.util.*;

class Solution {
    private static final int EMPTY = Integer.MAX_VALUE, GATE=0, WALL=-1;
    
    private static final List<int[]> dirs = Arrays.asList(
    new int[]{1,0},
        new int[]{-1, 0},
        new int[]{0, 1},
        new int[]{0, -1}
    );
    
    
    private int calDist(int[][] rooms, int startRow , int startCol){
        int m = rooms.length;
        int n = rooms[0].length;
        
        int dist[][] = new int[m][n];
        
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{startRow, startCol});
        
        while(!q.isEmpty()){
            int[] point = q.poll();
            int row = point[0];
            int col = point[1];
            
            for(int[] d: dirs){
                int r = row + d[0];
                int c = col + d[1];
                
                if(r<0 || c<0 || r>=m || c>=m || rooms[r][c]==WALL || dist[r][c] != 0){
                    continue;
                }
                
                dist[r][c] = dist[row][col] + 1;
                if(rooms[r][c]==GATE)return dist[r][c];
                
                q.add(new int[]{r,c});
            }
        }
        return Integer.MAX_VALUE;
    }
    
    public void wallsAndGates(int[][] rooms) {
        if (rooms.length == 0) return;
        for(int i=0;i<rooms.length;i++){
            for(int j=0;j<rooms[0].length;j++){
                if(rooms[i][j] == EMPTY){
                    rooms[i][j] = calDist(rooms, i, j);
                }
            }
        }
    }
}