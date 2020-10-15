import java.util.Scanner;
class Win 
{
	public static void main(String arguments[])
	{
		System.out.println("Enter size of each array");
		Scanner scan=new Scanner(System.in);
		int _size=scan.nextInt();
		System.out.println("Enter 1st array");
		int array1[]=new int[_size];
		for(int i=0;i<_size;i++)
		    array1[i]=scan.nextInt();
		System.out.println("Enter 2nd array");
		int array2[]=new int[_size];
		for(int i=0;i<_size;i++)
		   array2[i]=scan.nextInt();
		System.out.println("Enter 3rd array");
		int array3[]=new int[_size];
		for(int i=0;i<_size;i++)
		    array3[i]=scan.nextInt();
		System.out.println("Enter 4th array");
		int array4[]=new int[_size];
		for(int i=0;i<_size;i++)
		    array4[i]=scan.nextInt();
		System.out.println("Enter 5th array");
		int array5[]=new int[_size];
		for(int i=0;i<_size;i++)
		    array5[i]=scan.nextInt();
		
		MyQuickSort msq=new MyQuickSort();
		array1=msq.sort(array1);
		array2=msq.sort(array2);
		array3=msq.sort(array3);
		array4=msq.sort(array4);
		array5=msq.sort(array5);
		// for(int i=0;i<_size;i++)
		// 	System.out.println(array1[i]);
		Process pr=new Process();
		//let's store difference
		int difference[]=new int [_size];
		System.out.println("Least difference from 1st array ="+(difference[0]=pr.leastDifference(array1)));
		System.out.println("Least difference from 2nd array ="+(difference[1]=pr.leastDifference(array2)));
		System.out.println("Least difference from 3rd array ="+(difference[2]=pr.leastDifference(array3)));
		System.out.println("Least difference from 4th array ="+(difference[3]=pr.leastDifference(array4)));
		System.out.println("Least difference from 5th array ="+(difference[4]=pr.leastDifference(array5)));
		//sort to difference also
		difference=msq.sort(difference);
		//let's find out least differenc of difference array
		int _difference=pr.leastDifference(difference);
		System.out.print("\n Overall least difference is =");
		System.out.print(_difference);
	}
}
class Process
{
	int leastDifference(int array[])
	{
		int pastDifference=array[array.length-1]-array[0];//1st element and last element will give largest difference
		int currentDifference=0;
		int i=0;
		while(i<array.length-1)
		{
			currentDifference=array[i+1]-array[i];
			if(currentDifference<=pastDifference)//if current is less than past
				pastDifference=currentDifference;//simply update past
				i++;
		}
		return pastDifference;
	}
}





class MyQuickSort {
     
    private int array[];
    private int length;
 
    

    public int[] sort(int array[]) {
         //if array is empty
        if (array == null || array.length == 0) {
            return array;
        }
        this.array = array;
        length = array.length;
        quickSort(0, length - 1);
        return array;
    }
 
    private void quickSort(int lowerIndex, int higherIndex) {
         
        int i = lowerIndex;
        int j = higherIndex;
        // calculate pivot number, I am taking pivot as middle index number
        int pivot = array[lowerIndex+(higherIndex-lowerIndex)/2];
        // Divide into two arrays
        while (i <= j) {
            /**
             * In each iteration, we will identify a number from left side which 
             * is greater then the pivot value, and also we will identify a number 
             * from right side which is less then the pivot value. Once the search 
             * is done, then we exchange both numbers.
             */
            while (array[i] < pivot) {
                //find element from left side so increase left 
                i++;
            }
            while (array[j] > pivot) {
                //find element from right side so increase right 
                j--;
            }
            if (i <= j) {
                exchangeNumbers(i, j);
                //move index to next position on both sides
                i++;
                j--;
            }
        }
        // call quickSort() method recursively
        if (lowerIndex < j)
            quickSort(lowerIndex, j);
        if (i < higherIndex)
            quickSort(i, higherIndex);
    }
 
    private void exchangeNumbers(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}