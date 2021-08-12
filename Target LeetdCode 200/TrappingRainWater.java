class Solution {
    public int trap(int[] height) {
        int n = height.length;
        if(n<3) return 0;
        int []leftMax = new int[n];
        int []rightMax = new int[n];

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for(int i = 1;i<n;i++){
            leftMax[i] = Math.max(leftMax[i-1],height[i]);
            rightMax[n-i-1] = Math.max(rightMax[n-i], height[n-i-1]);
        }

        int ans = 0;
        for(int i=1;i<n-1;i++) {
            int area = Math.min(leftMax[i-1],rightMax[i+1]) - height[i];
            if(area>0) ans+=area;
        }
        return ans;
    }
    public int trap(int[] height, int n) {
        Stack<Integer> stack = new Stack<>();
        int ans=0;
        if(n == 0) return ans;
        stack.push(height[0]);

        for(int i=1;i<n;i++) {
            while(!stack.isEmpty() && stack.top()<height[i]) {
                ans+=(stack.top()-height[i]);
                stack.pop();
            }
            stack.push(height[i]);
        }
        return ans;
    }
}