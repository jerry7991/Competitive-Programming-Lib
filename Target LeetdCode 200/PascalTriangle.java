import java.util.*;

class PascalTraingle{
 public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        
        if(numRows == 0){
            return out;
        }
        
        out.add(new ArrayList<Integer>());
        out.get(0).add(1);
        for(int i=1;i<numRows;i++){
            int n=out.get(i-1).size()+1;
            out.add(new ArrayList<Integer>(n));
            for(int j=0;j<n;j++){
                if(j==0 || j==n-1){
                    out.get(i).add(1);
                } else{
                    out.get(i).add(out.get(i-1).get(j-1)+out.get(i-1).get(j));
                }
            }
        }
        return out;
    }

    public static void main(String[] args) {
        int n;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        List<List<Integer>> out = generate(n);
    }
}