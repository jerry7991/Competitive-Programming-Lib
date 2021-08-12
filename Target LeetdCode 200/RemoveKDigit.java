class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();
        char []arr = num.toCharArray();
        int i=0,n=num.length();

        while(i<n) {
            while(!stack.isEmpty() && k>0 && stack.peek()>arr[i]){
                k--;
                stack.pop();
            }
            stack.push(arr[i++]);
        }
        
        while(!stack.isEmpty() && k>0){
            stack.pop();
            k--;
        }
        
        StringBuilder str = new StringBuilder();


        while(!stack.isEmpty()){
            str.append(stack.peek());
            stack.pop();
        }
        
        str.reverse();
        while(str.length()>0 && str.charAt(0)=='0') {
           str.deleteCharAt(0);
        }
        
        if(str.length() == 0) {
            return "0";
        }
        
        return str.toString();
    }
}