class Solution {
    public int nextGreaterElement(int n) {
        char [] number = (n+"").toCharArray();
        n = number.length;
        int ans=0, i=n-1;
        while(i>0){
            if(number[i-1]<number[i]) break;
            i--;
        }

        if(i == 0) return -1;

        int small =i;
        for(int j=i+1;j<n;j++){
            if(number[j]>number[i-1] && number[small]>number[j]){
                small=j;
            }
        }
        

        char t = number[small];
        number[small]=number[i-1];
        number[i-1]=t;

        Arrays.sort(number, i, n);

        long res = Long.parseLong(new String(number));
        return res > Integer.MAX_VALUE?(int)-1:(int)res;
    }
}