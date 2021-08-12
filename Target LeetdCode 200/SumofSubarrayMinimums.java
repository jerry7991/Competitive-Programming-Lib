class Solution {
    public int sumSubarrayMins(int[] arr) {
        Stack<Integer> stack  = new Stack<Integer>();
        int n = arr.length;
        int []ple = new int[n];
        int []nle = new int[n];


        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                stack.pop();
            }
            ple[i] = stack.isEmpty() ?  i + 1 : i - stack.peek();
            stack.push(i);
        }

        stack.clear();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            nle[i] = stack.isEmpty() ? n - i : stack.peek() - i;
            stack.push(i);
        }

        long ans = 0;
        int mod = 1e0 + 7;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long)ple[i] * nle[i] * arr[i]) % mod;
        }
        return (int)(ans % mod);
    }
}