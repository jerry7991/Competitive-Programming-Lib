import java.util.Scanner;
class first
{
	int a,b;
	public static void getReverse(int []arr , int n, int []arr2)
	{
		for (int i=0 ;i<n ;i++ ) {
			arr2[i]=arr[n-i-1];
		}
		return;
	}

	public static void swap(first f)
	{
		int temp=f.a;
		f.a=f.b;
		f.b=temp;
		return;
	}
	public static void main( String args[])
	{
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int arr[]=new int[n];
		for (int i=0;i<n ;i++ ) {
			arr[i]=scan.nextInt();
		}
		int arr2[]=new int[n];
		getReverse(arr , n , arr2);
		for (int i=0;i<n ;i++ ) {
			System.out.println(arr2[i]);
		}
		first f=new first();
		f.a=10;
		f.b=20;
		swap(f);
		System.out.println(f.a+" "+f.b);
	}
}