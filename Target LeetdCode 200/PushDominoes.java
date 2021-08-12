import java.util.*;

class Solution {

    public String pushDominoes(String s) {
        char []arr = s.toCharArray();
        int n = arr.length;
        int []forces = new int[n];
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'R') force = n;
            else if (arr[i] == 'L') force = 0;
            else force = Math.max(force - 1, 0);

            forces[i] += force;
        }

        force = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 'L') force = 'N';
            else if (arr[i] == 'R') force = 0;
            else force = Math.max(force - 1, 0);
            forces[i] += force;
        }

        StringBuilder str = new StringBuilder();

        for (int i : forces) {
            if (i > 0) str.append('R');
            else  if (i < 0) str.append('L');
            else str.append('.');
        }
        return str.toString();
    }

}