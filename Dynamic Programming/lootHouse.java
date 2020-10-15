import java.util.Scanner;
class Solution
{
	private static int getSolution(int arr[] , int start , int n)
	{
		//base case
		//i.e. theif don't have any left house then he can't steal money 
		if (start>=n) {
			return 0;
		}
		//now theif has two option
		//first he can choose the current house
		//if he selected current house then according to question he can not select the next consecutive house
		//so increase start of house by 2;
		int nextHouse=start+2;
		int option1=arr[start]+getSolution(arr , nextHouse , n);
		//and second option is he can skip curr house then he will be able to steal the just next house cause he
		//he didn't loot curr house.. so nextHouse will be just start+1;
		nextHouse=start+1;
		int option2=getSolution(arr , nextHouse ,n);
		return Math.max(option1 , option2);
	}
	private static int getDpSolution(int money[] , int currHouse , int n , int dp[])
	{
		//if theif has looted all the house then he wouldn't loot next any house
		if (currHouse>=n) {
			return 0;
		}
		//if we have solved that what is the max money if thief start looting from any house then
		//just return them,we don't want to recalculate ...Ok!!!!!!
		if (dp[currHouse]!=-1) {
			//if not equal to -1 then theif allready know what is the max money
			return dp[currHouse];
		}
		//else we have to calculate for currHouse
		//now for each house we have two choice either we can choose that house to be looted or not
		//option1:- if we choose currHouse to be looted then we cann't loot the just next houst
		//so
		int nextHouse=currHouse+2;//cause we can't loot just next if we are looting current house
		int option1=money[currHouse]+getDpSolution(money , nextHouse , n , dp);
		//option2 if we don't loot the current house then we can loot just next also
		nextHouse=currHouse+1;
		int option2=getDpSolution(money , nextHouse , n , dp);//no money added cause we didn't loot currHouse
		int ans=(option1>option2)?option1:option2;
		//now we have solved for particular current house so we should store it for further use
		//because we don't want to do repeated job
		dp[currHouse]=ans;
		return ans;
	}
	private static int getDpSolution(int money[] , int currHouse , int n)
	{
		if(n==1)
            return money[0];
        if(n==2)
        {
            return Math.max(money[1],money[0]);
        }
		int dp[]=new int[n];
		for (int i=0;i<n ;i++ ) {
			dp[i]=0;
		}
		dp[n-1]=money[n-1];
		dp[n-2]=money[n-2];
		for (int i=n-3;i>=0  ;i-- ) {
			dp[i]=Math.max(money[i]+dp[i+2] , dp[i+1]);
		}
		// for (int i=0;i<n ;i++ ) {
		// 	System.out.println(dp[i]);
		// }
		return dp[0];
	}
	public static int getMaxMoney(int arr[]  , int n)
	{
		//return getSolution(arr , 0 , n);
		int dp[]=new int[n+1];
		for (int i=0 ;i<n+1 ;i++ ) {
			dp[i]=-1;//by default put -1
		}
		//return getDpSolution(arr , 0 , n ,dp);
		return getDpSolution(arr , 0 , n);
	}
}
public class lootHouse {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int arr[] = new int[n];
		for(int i=0; i<n; i++){
			arr[i] = s.nextInt();
		}
		System.out.println(Solution.getMaxMoney(arr, n));
	}
}
