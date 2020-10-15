public interface Stack
{
	public int size();
	public boolean isEmpty();
	public Object top() throws StackEmptyException;

	// for update methods

	public void push(Object element);
	public Object pop() throws StackEmptyException;
}