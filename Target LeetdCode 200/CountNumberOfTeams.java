import java.util.*;


class Solution {
    public int numTeams(int[] arr) {
        int n = arr.length, res = 0;

        for (int i = 0; i < n; i++) {
            int []less = new int[2];// 0  for left and 1 for right
            int []greater = new int[2]; // 0 for left and 1 for right
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (arr[i] > arr[j]) {
                    greater[i < j ? 1 : 0]++;
                }

                if (arr[i] < arr[j]) {
                    less[i < j ? 1 : 0]++;
                }
            }
            res += (less[0] * greater[1] + less[1] * greater[0]);
        }
        return res;
    }
}