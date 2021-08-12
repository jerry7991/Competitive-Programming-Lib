class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int []ans = new int[n];
        
        Map<Integer, Integer> nextGreater = new HashMap<>();

        Stack<Integer> stack = new Stack<Integer>();

        for(int i=m-1;i>=0;i--){
            while(!stack.isEmpty() && stack.peek()<nums2[i]) stack.pop();
            if(!stack.isEmpty())
                nextGreater.put(nums2[i], stack.peek());
            stack.push(nums2[i]);
        }

        for(int i=0;i<n;i++){
            ans[i] = nextGreater.getOrDefault(nums1[i], -1);
        }

        return ans;
    }
}