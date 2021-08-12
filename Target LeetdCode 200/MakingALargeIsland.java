class Solution {
    int r,c;

    int []dx={1,-1,0,0};
    int []dy={0,0,1,-1};


    private int solve(int [][]grid, int i, int j, int change){
        int ans = 0;
        int val = grid[i][j];
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            int x = i+dx[k], y=j+dy[k];
            if(x<0 || y<0 || x==r || y==c || grid[x][y] == 2 || (grid[x][y] == 0 && change == 1)) continue;
            ans = Math.max(ans, 1+solve(grid,x,y, change^(grid[x][y]==0?1:0)));
        }
        grid[i][j]=val;
        return ans;
    }

    public int largestIsland(int[][] grid) {
        r= grid.length; c = grid[0].length;
        int ans = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1)
                ans = Math.max(ans, solve(grid,i,j,0));
            }
        }

        Queue<int[]> level = new LinkedList<>();
        for(int i=0;i<r; i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 0) {
                    level.add(new int[]{i,j});
                }
            }
        }
        if(level.isEmpty()) {
            level.add(new int[]{0,0});
        }

        int maxLevel = 1;
        while(!level.isEmpty()){
            int n = level.size();
            maxLevel++;
            while(n-->0){
                int []temp = level.remove();
                int x = temp[0], y = temp[1];
                for(int i=0;i<4;i++){
                    int nx = x+dx[i], ny = y+dy[i];

                    if(Math.min(nx,ny)<0 || nx == r || ny == c || grid[nx][ny]==0) continue;
                    if(grid[nx][ny] == 1) {
                        grid[nx][ny]=2;
                        level.add(new int[]{nx,ny});
                    }

                }
            }
        }
        return maxLevel;
    }
}