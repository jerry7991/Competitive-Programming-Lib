//https://codezen.codingninjas.com/practice/470/750/longest-subset-zero-sum
//hints:-https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
import java.util.HashMap;
import java.util.Scanner;
class LongestSubArraySum0
{
	private static int getLength(int n,int arr[])
	{
		HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
		int sum=0,maxLength=0;
		for (int i=0;i<n ;i++ ) {
			sum+=arr[i];
			if (arr[i]==0 && maxLength==0) {
				//i.e. base case
				maxLength=1;
			}
			if (sum==0) {
				maxLength=i+1;//i.e current is length of max longest sum 0
			}
			if (map.containsKey(sum)) {
				//i.e. we have been traversing a path which some gave 0
				int value=map.get(sum);
				maxLength=Math.max(maxLength , i-value);
			}else{
				//insert cause this is new one
				map.put(sum , i);
			}
		}
		return maxLength;
	}
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int []arr=new int[n];
		for (int i=0 ;i<n ;i++ ) {
			arr[i]=scan.nextInt();
		}
		System.out.println(getLength(n,arr));
	}
}