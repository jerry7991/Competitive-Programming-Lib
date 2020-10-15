import java.util.Scanner;
class TestInputStack
{
	public static void main(String[] args) 
	{
		Scanner scan=new Scanner(System.in);
		ArrayStack arrayStack; 
		System.out.println("Enter the size of Stack (Optional) \n default size is 1024");
		int _size=0;
		arrayStack=new ArrayStack(_size);
		_size=scan.nextInt();
		if(_size != 0)
			{
				arrayStack=new ArrayStack(_size);
			}else if(_size==0)
			{
				System.out.println("Enter a valid size");
				System.exit(0);
			}
			else{
						arrayStack=new ArrayStack();
				 }

		 				System.out.println("Enter the element of Which is going to Push onto Stack");
						for(int i=0;i<_size;i++)
						{
						 arrayStack.push(scan.nextInt());
						}
		System.out.println("Your data is popped into the stack.. Please Enter your choice for operation \n\t Push \n\t Pop \n\t Display \n\t SearchTopItem \n\t CheckSize");
		while(scan.hasNext())
		{
		 switch(scan.next())
		 {
			case "SearchTopItem" :
						System.out.println("Top item is "+arrayStack.top());
						break;
			case "CheckSize" :
						System.out.println("Size of Stack is "+arrayStack.size());
						break;
			case "Pop" :
						System.out.println("This item "+arrayStack.pop()+" popped");
			case "Display" :
						arrayStack.display();
						break;
		 }	

		}
	}
	}	
// }Display SearchTopItem CheckSize Pop  SearchTopItem CheckSize Pop SearchTopItem CheckSize Pop