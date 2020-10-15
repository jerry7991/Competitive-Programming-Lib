import java.util.Scanner;
import java.util.*;
class Main
{
	static Scanner sc=new Scanner(System.in);
	public static int [] takeInput()
	{
		int n=sc.nextInt();
	    int arr[]=new int[n];
	    for(int  i=0;i<n;i++)
	    {
	    	arr[i]=sc.nextInt();

	    }
	    return arr;
	}

	public static int  arraySum(int  [] arr)
	{
		int Sum1=0;
		int n=arr.length;
		// int Nsum=naturalSum(n);
		int Sum2=naturalSum(n-1);
		for (int  i=0;i<n; i++)
		 {
		 	Sum1=Sum1+arr[i];
		 }
		 	// int Dup=(Sum1-Nsum);
		 // System.out.println(Sum1);
		 // System.out.println(Sum2);
		 int Dup=(Sum1-Sum2);
		 return Dup;
	} 

	public static int naturalSum(int n)
	{
		int Sum2=0;
			Sum2=(n)*(n-1)/2;
		return Sum2;
	}

	public static void main(String[] args)
	 {
	 	int arr[]=takeInput();
	 	
	 	 System.out.print(arraySum(arr));

		
	 }
}