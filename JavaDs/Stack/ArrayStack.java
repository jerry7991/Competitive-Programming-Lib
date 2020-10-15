public class ArrayStack implements Stack
{
	// we implement the Stack interface which currently created..
	public static final int CAPACITY=1024;
	//it definds the default size of stack
	private int N;
	public Object S[]; //S is an array type object,which hold the elements of stack
	private int t=-1; //it will give the top position of stack

	public ArrayStack() //default cunstrocter
	{
		this(CAPACITY);
	}
	public ArrayStack(int cap)  //cunstroctor overloading
	{
		N=cap;
		S=new Object[N];
	}

	//let's give the functionality of methods which declared in Stack Interface

	public int size()
	{
		return(t+1);
	}

	public boolean isEmpty()
	{
		return (t<0);
	}

	public void push(Object obj) throws StackFullException
	{
		if(size()==N) {throw new StackFullException("Stack OverFlow");}
			S[++t]=obj;
	}

	public Object top() throws StackEmptyException
	{
		//for sellecting the top element onto stack first we have to check whether the stack is empty or not....
		if(isEmpty())
			 {throw new StackEmptyException("Stack is empty");}
		return S[t];
	}

	public Object pop() throws StackEmptyException
	{
		Object element;
		if(isEmpty())
			{throw new StackEmptyException("Stack is empty");}

		element=S[t]; //store element to return
		S[t--]=null;  //clearing the memory from disk and decrement the position
		return element;
	}

	public void display()
	{
		while(t >= 0)
		{
			System.out.println("\t"+S[t]);
			t--;
		}
	}
}