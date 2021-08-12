class Trie{
    public Map<Character, Trie> children;
    public boolean eow;
    public int cnt;
    public Trie(){
        this.children = new HashMap<>();
        this.eow=false;
        this.cnt=0;
    }
}

class Solution {

    private StringBuilder str;
    private char []arr;
    private int n,start,max;
    private Trie root;


    private boolean searchOrInsert(StringBuilder st) {
        Trie temp = root;
        boolean flag = false;
        for(int i=0;i<st.length();i++){
            Trie child = temp.children.getOrDefault(st.charAt(i), null);
            if(child == null) {
                child = new Trie();
                flag = true;
            }
            temp.children.put(st.charAt(i), child);
            temp = child;
        }

        temp.cnt++;
        temp.eow=true;

        return temp.cnt >=2 && !flag;
    }

    private boolean isPossible(int k){
        int i=0;

        
        StringBuilder st = new StringBuilder();

        while(i<k){
            st.append(arr[i++]);
        }

        while(i<n) {
            if(searchOrInsert(st)){
                if(k>max){
                    max = k;
                    start = i-k;
                }
                return true;
            }
            st.deleteCharAt(0);
            st.append(arr[i++]);
        }

        if(searchOrInsert(st)){
            if(k>max){
                max = k;
                start = i-k;
            }
            return true;
        }              

        return false;
    }

    public String longestDupSubstring(String s) {
      arr  = s.toCharArray();
      str = new StringBuilder();
      n = s.length();start=0;max=0;
      int l = 1, r = n;

      root= new Trie();
      
      while(l<=r) {
        int m = (l+r)/2;
        if(isPossible(m)) {
            l = m+1;
        }else {
            r=m-1;
        }
      }
      return str.substr(start, start+max);
    }
}