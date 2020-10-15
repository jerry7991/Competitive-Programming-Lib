import java.util.Scanner;
class InefficientAlgorithm
{
	public static void main(String arsg[])
	{
		Scanner scan=new Scanner(System.in);
		int stockPrice[];
		int spanTime[];
		System.out.println("Enter the length of the date");
		int _totalDay=scan.nextInt();
		spanTime=new int[_totalDay];
		stockPrice=new int[_totalDay];
		System.out.println("Enter the data about stock price per day");
		for(int i=0;i<=_totalDay-1;i++)
		{
			System.out.print("Stock Price for Day["+i+"] = ");
			stockPrice[i]=scan.nextInt();
		}
		for(int i=_totalDay;i>0;i++)
		{
			int k=0;boolean done=false;
			while(true)
			{
				if(stockPrice[i-k]<=stockPrice[i])
				{
					k++;
				}else{
					done=true;
				}
				if((i-k)<=0 && (k==i || done) )
					break;
			}
			 spanTime[i]=k;
		}
		System.out.println("Span Time are given Bellow");
		for(int i=0;i<=_totalDay-1;i++)
		{
			System.out.println(spanTime[i]);
		}
	}
}