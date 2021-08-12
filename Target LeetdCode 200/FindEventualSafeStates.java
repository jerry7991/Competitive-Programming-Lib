class Solution {
    private static void doDfs(int [][]graph,  int []color, int u) {
        color[u] = 1;
        for (int v : graph[u]) {
            if (color[v] == 2) break;
            if (color[v] == 1 || doDfs(graph, safe, seen, v)) {
                return false;// was cycle
            }
        }
        color[u] = 2;
    }
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        List<Integer> safe = new ArrayList<Integer>();
        int []color = new int[n];
        for (int i = 0; i < n; i++) {
            if (doDfs(graph, color, i)) {
                safe.add(i);
            }
        }

        Collections.sort(safe);

        return safe;
    }
}