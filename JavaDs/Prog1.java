import java.util.*;
class Prog1
{
	public static void setPrime(boolean [] prime , int n)
	{          
        for(int p = 2; p*p <=n; p++) 
        { 
            // If prime[p] is not changed, then it is a prime 
            if(prime[p] == true) 
            { 
                // Update all multiples of p 
                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
	}
	public static void main(String[] args) {
		int n;
		int counter=0;
		Scanner scan = new Scanner(System.in);
		n =	scan.nextInt();
		boolean prime[] = new boolean[n+1]; 
        for(int i=0;i<n;i++) 
            prime[i] = true; 
        setPrime(prime , n);	//It will take O(log(logN));
        int curr_prime_sum=2;
        for (int i=3;i<n ;i++ ) //and this O(N) so finally O(N)
        {

        	if (prime[i])
        	{
        		curr_prime_sum	+= i;
        		if (curr_prime_sum>n) 
        		{
        		        continue;
				}   
				if(prime[curr_prime_sum])     		
				{
					counter++;
				}
        	}        	
        }
        System.out.println(counter);
	}
}