/*
    Time complexity : O(V^3)
    Space complexity : O(1)

    Where 'V' is the number of vertices.

*/



import java.util.ArrayList;
import java.util.Collections;

public class Solution {

    public static int triangleInGraph(ArrayList<ArrayList<Integer>> graph, int v) {

        int ans = 0;

        for (int i = 0; i < v; i++) {

            for (int j = i + 1; j < v; j++) {

                for (int k = j + 1; k < v; k++) {

                    if (graph.get(i).get(j) == 1
                            && graph.get(j).get(k) == 1
                            && graph.get(k).get(i) == 1) {

                        ans++;

                    }

                }
            }
        }

        return ans;
    }
}