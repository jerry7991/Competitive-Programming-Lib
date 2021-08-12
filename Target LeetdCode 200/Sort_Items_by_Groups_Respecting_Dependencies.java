class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> bT) {
        ArrayList<Integer> []edge = new ArrayList[n];
        for (int i = 0; i < n; i++)edge[i] = new ArrayList<Integer>();

        int []indegree = new int[n];

        for (int i = 0; i < bT.size(); i++) {
            for (Integer j : bt.get(i)) {
                edge[i].add(j);
                indegree[j]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {

            }
        }
    }
}