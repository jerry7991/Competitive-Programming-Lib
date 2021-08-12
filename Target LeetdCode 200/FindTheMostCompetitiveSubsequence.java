class Solution {
  public int[] mostCompetitive(int[] nums, int k) {
    int n = nums.length, i = 0;
    Stack<Integer> stack = new Stack<Integer>();

    while (i < n) {
      while (!stack.isEmpty() && (k - stack.size()) < (n - i) && stack.peek() > nums[i]) {
        stack.pop();
      }
      if (stack.isEmpty() || stack.size() < k)
        stack.push(nums[i]);
      i++;
    }


    int []arr = new int[k];

    while (!stack.isEmpty()) {
      arr[--k] = stack.peek();
      stack.pop();
    }

    return arr;
  }
}