import java.util.Scanner;
import java.util.*;

public class Solution {
    
    public static  void printBsTraversal(int adjMatrix[][] , int source ,int nVertex )
    {
        Queue <Integer> queue = new LinkedList<> ();
        boolean visitedvertex[] = new boolean [nVertex+1];
        for(int i = 1 ; i<=nVertex ; i++)
        {
            visitedvertex[i] = false;
        }
        queue.add(source);
            visitedvertex[source] = true;
        while(!queue.isEmpty())
        {
           int currentVertex =  queue.poll();
               System.out.println(currentVertex +" ");
            for(int dest=1 ; dest<= nVertex ; dest++ )
            {
              if ( adjMatrix[currentVertex][dest]==1 )
              {
                continue;
              }
                  if(! visitedvertex[dest])
                  {
                      queue.add(dest);
                          visitedvertex[dest] = true;
                  }
            }
        }
        
    }

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int V = s.nextInt();
		int E = s.nextInt();
        
        int adjMatrix[][] = new int [V][V];
       
        for(int i=1 ;i<=E ;i++)
        {
            int sr =s.nextInt();
            int ds = s.nextInt();
             adjMatrix[sr][ds] = 1;
             adjMatrix[ds][sr] = 1;
            
            
        }
    
        printBsTraversal(adjMatrix , 1 , V);

		/* Write Your Code Here
		 * Complete the Rest of the Program
		 * You have to take input and print the output yourself
		 */
	}
}