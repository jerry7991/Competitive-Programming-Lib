import java.util.*;

class Solution {
    public int findPeakElement(int[] nums) {
        int n=nums.length;
        for(int i=1;i<n;i++){
            if(nums[i]>Math.max(nums[i-1], (i+1<n)?nums[i+1]:Integer.MIN_VALUE)){
                return i;
            }
        }
        return 0;
    }
}


class FindPeakElement {
    public static void main(String[] args) {        
        Scanner scan = new Scanner(System.in);
        int n=scan.nextInt();
        int []arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = scan.nextInt();
        System.out.println((new Solution()).findPeakElement(arr));
    }
}