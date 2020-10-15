import java.util.Scanner;
class Details
{
	int rollNumber;
	int age;
	public Details()
	{
		System.out.println("Inside default constructer");
	}
	public static Details[] Details(int size)
	{
		Details []dt=new Details[size];
		for(int i=0;i<size;i++)
		{
			dt[i]=new Details();
		}
		return dt;
	}
		public static void main(String[] args) {
	
		Details []dt=Details.Details(3);
		dt[0].rollNumber=18;
		dt[0].age=21;
		System.out.println(dt[0].rollNumber+" "+dt[0].age);
}
}