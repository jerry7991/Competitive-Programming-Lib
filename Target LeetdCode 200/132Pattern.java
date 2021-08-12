class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length, s3 = Integer.MIN_VALUE;

        Stack<Integer> stack = new Stack<>();

        for(int i=n-1;i>=0;i--){
            if(nums[i]<s3) return true;
            else while(!stack.isEmpty() && stack.peek()<nums[i]){
                s3 = stack.peek();
                stack.poll();
            }
            stack.push(nums[i]);
        }
        return false;
    }
}