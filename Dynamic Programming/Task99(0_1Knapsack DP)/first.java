import java.util.Scanner;

public class Main {
	
    static final long mod=(long)Math.pow(10,9)+7;
    
    
    
    public static void countStrings(int p1,int n,int k)
    {
        long dp[][][]=new long[n+1][k+1][2];
        dp[1][0][0]=1l;
        dp[1][0][1]=1l;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i&&j<k+1;j++)
            {
                dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]);
                dp[i][j][1]=dp[i-1][j][0];
                
                if(j-1>0)
                {
                    dp[i][j][1]=(dp[i][j][1]+dp[i-1][j-1][1]);
                }
            }
        }
        long ans=(dp[n][k][0]+dp[n][k][1]);
        System.out.println(p1+" "+ans);
        
    }
	
	public static void main(String[] args) {
		// Write your code here
        Scanner in = new Scanner(System.in);
        int p=in.nextInt();
        for(int i=0;i<p;i++)
        {
            int p1,n,k;
            p1=in.nextInt();
            n=in.nextInt();
            k=in.nextInt();
            countStrings(p1,n,k);
        }

	}

}
for(i=2;i<=100;i++)
 { 
    dp[i][i-1][0]=0;
     dp[i][i-1][1]=1;
      dp[i][0][0]=dp[i-1][0][0]+dp[i-1][0][1];
       dp[i][0][1]=dp[i-1][0][0];
        if(dp[i][0][0]>=mod)dp[i][0][0]-=mod; 
}