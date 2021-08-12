class Solution {
    private boolean isPalindrom(char []arr, int j){
        int i=0;
        while(i<j){
            if(arr[i++]!=arr[j--]) return false;
        }
        return true;
    }
    public String shortestPalindrome(String s) {
            char [] arr = s.toCharArray();

            StringBuilder ans = new StringBuilder();
            int n = arr.length;
            for(int i=n-1;i>=0;i--){
                if(isPalindrom(arr, i)){
                    break;
                }
                ans.append(arr[i]);
            }
            ans.append(s);
            return ans.toString();
    }
}