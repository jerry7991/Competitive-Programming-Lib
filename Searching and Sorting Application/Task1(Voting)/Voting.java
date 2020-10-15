import java.util.*;
public class Voting
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		//number of zone is fixed
		int zone[]=new int[5];
		System.out.println("Enter the number of Candidate in zone");
		for(int i=0;i<zone.length;i++)
		{
			System.out.println("For Zone"+(i+1));
			zone[i]=scan.nextInt();
		}
		// initialize each zone with there respective size
		int arrayZone1[]=new int[zone[0]];
		int arrayZone2[]=new int[zone[1]];
		int arrayZone3[]=new int[zone[2]];
		int arrayZone4[]=new int[zone[3]];
		int arrayZone5[]=new int[zone[4]];
	
		System.out.println("Enter the ID for Zone1 Candidate");
		for(int i=0;i<arrayZone1.length;i++)
		{
			arrayZone1[i]=scan.nextInt();
		}
		System.out.println("Enter the ID for Zone2 Candidate");
		for(int i=0;i<arrayZone2.length;i++)
		{
			arrayZone2[i]=scan.nextInt();
		}
		System.out.println("Enter the ID for Zone3 Candidate");
		for(int i=0;i<arrayZone3.length;i++)
		{
			arrayZone3[i]=scan.nextInt();
		}
		
		System.out.println("Enter the ID for Zone4 Candidate");
		for(int i=0;i<arrayZone4.length;i++)
		{
			arrayZone4[i]=scan.nextInt();
		}
		System.out.println("Enter the ID for Zone5 Candidate");
		for(int i=0;i<arrayZone5.length;i++)
		{
			arrayZone5[i]=scan.nextInt();
		}
		//Process class constructer needs 5 array object..
		Process process=new Process(arrayZone1,arrayZone2,arrayZone3,arrayZone4,arrayZone5);
		
		process.processSort();
		//array sorted so let's merge it. merge return array object of type int
		int finalMergedZoneId[]=process.IdMerge();

		ElectedCondidates _electedCondidates=new ElectedCondidates();
		int electedID[]=_electedCondidates.election(finalMergedZoneId);
		int numberOfCandidate=0;
		System.out.println("ElectedCondidates with their respective id is -");
		for(int i=0;i<electedID.length;i++)
		{
			if(electedID[i]!=0)
			{
				numberOfCandidate++;
			System.out.print(electedID[i]);
			System.out.print("  ");
			}
		}
		System.out.println("Total number of Elected Condidates ="+numberOfCandidate);

	}
} 
 class Process
{
	//intstance variable which I'm going to use latter in this class
	int ArrayZone1[];
	int ArrayZone2[];
	int ArrayZone3[];
	int ArrayZone4[];
	int ArrayZone5[];
	Process( int [] ArrayZone1,int [] ArrayZone2,int [] ArrayZone3,int [] ArrayZone4,int [] ArrayZone5)
	{
		//initialize all instance variable in this cunstructor
		this.ArrayZone1=ArrayZone1;
		this.ArrayZone2=ArrayZone2;
		this.ArrayZone3=ArrayZone3;
		this.ArrayZone4=ArrayZone4;
		this.ArrayZone5=ArrayZone5;
	}
	void processSort()
  {
  	//we are going to use quick sort for better time complexity
	MyQuickSort mqs=new MyQuickSort();
	ArrayZone1=mqs.sort(ArrayZone1);
	ArrayZone2=mqs.sort(ArrayZone2);
	ArrayZone3=mqs.sort(ArrayZone3);
	ArrayZone4=mqs.sort(ArrayZone4);
	ArrayZone5=mqs.sort(ArrayZone5);
  }
  //now we are going to merge 2 array with in 1 and return them
   int[] processMerge(int firstArray[],int [] secondArray)
   {
   	int firstIndex=0;
   	int secondIndex=0;
   	int maxLength=((firstArray.length)+(secondArray.length));
   	int mergedArray[]=new int[maxLength];
   	for(int i=0;i<maxLength;i++)
   	{
   		//if first array end ,normally copy the rest part of second array
   		if(firstIndex==firstArray.length)
   		{
   			while(secondIndex<secondArray.length)
   			{
   				mergedArray[i]=secondArray[secondIndex++];
   				i++;
   			}
   		}
   		else 
   		{
   			//if seccond array end,normally copy the rest part of first array
   			if(secondIndex==secondArray.length)
   		{
   			while(firstIndex<firstArray.length)
   			{
   				mergedArray[i]=firstArray[firstIndex++];
   				i++;
   			}
   		}
   		else
   		{
   			//other wise merge them in there increasing order
   			if(firstArray[firstIndex]<=secondArray[secondIndex])
   			{
   				mergedArray[i]=firstArray[firstIndex++];
   			}
   			else
   			{
   				mergedArray[i]=secondArray[secondIndex++];
   			}
   		}
   		}
   	}
   	return mergedArray;
   }
   int[] IdMerge()
   {
   	//first merge 1st and 2nd
   	int mergedArray1[]=processMerge(ArrayZone1,ArrayZone2);
   	//then merge 3rd and fourth
   	int mergedArray2[]=processMerge(ArrayZone3,ArrayZone4);
   	//merge (1st and 2nd) with (3rd and 4th)
   	mergedArray1=processMerge(mergedArray1,mergedArray2);
   	//merge (1st ,2nd,3rd,4th) with 5th zone
   	mergedArray2=processMerge(mergedArray1,ArrayZone5);
   	//return finall merged array...which have all zone
   	return mergedArray2;
   }
}
class ElectedCondidates
{
	//in this method we are going to find out the elected condidate
	int[] election(int zoneIdForElection[])
	{
	int electedID[]=new int[(zoneIdForElection.length)/3];
	//because best condition is when all element is 3 times in array
		int electedIDIndex=0;
		//because allready 2 id equals

		for(int i=0;i<zoneIdForElection.length-1;i++)
		{
		    int counter=1;
			int key=zoneIdForElection[i];
			while((i<zoneIdForElection.length-1) && (key==zoneIdForElection[i+1]))
			{
				counter++;
				i++;
			}
			if(counter>=3)
			{
				electedID[electedIDIndex++]=key;
				
			}
		}
		//return electedId
		return electedID;
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