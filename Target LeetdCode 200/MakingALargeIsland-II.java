class Solution {
    int []dx={1,-1,0,0};
    int []dy={0,0,1,-1};
    int n;

    private Set<int[]> paint(int i, int j){
        Set<int[]> set = new HashSet<>();
        for(int k=0;k<4;k++){
            int x = i+dx[k], y =j+dy[k];
            if(x<0 || y<0 || x == n || y == n) continue;
            set.add(new int[]{x,y});
        }
        return set;
    }

    private int doDfs(int [][]grid, int i, int j,int color) {
        int ans=1;
        grid[i][j]=color;
        for(int []v:paint(i,j)){
            if(grid[v[0]][v[1]]==1) {
                ans+=doDfs(grid,v[0],v[1],color);
            }
        }
        return ans;
    }
    public int largestIsland(int[][] grid) {
       
        HashMap<Integer, Integer> colorLen = new HashMap<>();

        int color = 2;// 0 and 1 are already there
        n=grid.length;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1) continue;
                colorLen.put(color, doDfs(grid,i,j,color));
                color++;
            }
        }
        System.out.println(colorLen);

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) continue;
                int curr = 1;
                Set<Integer> set = new HashSet<>();
                for(int []v  : paint(i,j)) {
                    set.add(grid[v[0]][v[1]]);
                }
                for(Integer s:set) curr+=colorLen.getOrDefault(s,0);
                ans = Math.max(curr,ans);
            }
        }
        return ans == 0?(n*n):ans;
    }
}