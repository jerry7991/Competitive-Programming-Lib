import java.util.Scanner;
class NumberToString
{
	public static void main(String arguments[])
	{
		System.out.println("Enter your Number which has atmost 4 digit");
		Scanner scan=new Scanner(System.in);
		int number=scan.nextInt();
		int temp=number;int counter=0;int remender=0;
		while(temp>0)
		{
			temp/=10;
			counter++;
		}
		char array[]=new char[counter];
		while(number>0)
		{
			remender=number%10;
			number/=10;
			array[--counter]=(char)(remender+'0');
		}
		// for(int i=0;i<array.length;i++)
		// {
		// 	System.out.println(array[i]);
		// }
		ConvertToWord ctw=new ConvertToWord();
		ctw.convert(array);
	}
}
class ConvertToWord
{
  void convert(char []number)
  {
  	int _length=number.length;
    if(number.length==0)
    {
    	System.out.println("No Number found");
    	return;
    }
    else if(number.length>4)
    {
    	System.out.println("Number is out of bound ");
    	return;
    }
    else
    {
    	String []single_digits={
    							 "zero","one","two","three","four","five","six","seven","eight","nine"
    								};
    	String []double_digits={
    							 "","ten","eleven","twelve","thirteen","fourteen","fiveteen","sixteen",
    							 "seventeen","eighteen","nineteen"
    								};
    	String []tens_multiplication={
    							"","","twentyn","thirty","fourty","fifty","sixty","seventy","eighty","ninety"
    									};	
    	String []tens_power={
    							"houndred","thousand"
    							};														
		if(_length==1)
		{
			System.out.println(single_digits[number[0]-'0']);
			return;
		}
		int indexValue=0;
		while(indexValue<number.length)
		{
			if(_length>=3)
			{
				if(number[indexValue]-'0'!=0)//first digit is not 0
				{
					System.out.println(single_digits[number[indexValue]-'0']+" ");
					System.out.println(tens_power[_length-3]+" ");
				}
				--_length;
			}
			else
			{
			//code for last two digit	
				//we have to handle last digit if it contains 10->19
				if(number[indexValue]-'0'==1)
				{
					int index=number[indexValue]-'0'+number[indexValue+1]-'0';
					 System.out.println(double_digits[index]+" ");
					 return;
				}
				//we have to handle last digit if it contains 20
				else if(number[indexValue]-'0'==2 && number[indexValue+1]-'0'==0)
				{
					System.out.println("twenty");
					return;
				}
				//we have to handle last digit if it contains 21-99
				else
				{
					//lets store 1st digit
					int i=(number[indexValue]-'0');
					if(i>0)
						System.out.println(tens_multiplication[i]+" ");
					else
						System.out.println(" ");//if its zero then ingore simply it
					indexValue++;
					if(number[indexValue]-'0'!=0)
						System.out.println(single_digits[number[indexValue]-'0']);//simply print last digit
				}
			}
			indexValue++;
		}
    }
  }
}