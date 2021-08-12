class Solution {
    boolean [][]dp;
    List<List<String>> list;
    void solve(String s, List<String> path, int i) {
        if (i == s.length()) {
            if (path.size() > 0) {
                list.add(new ArrayList<String>(path));
            }
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (dp[i][j]) {
                path.add(s.substring(i, j + 1));
                solve(s, path, j + 1);
                path.remove(path.size() - 1);
            }
        }


    }

    public List<List<String>> partition(String s) {
        char [] arr = s.toCharArray();
        int n = arr.length;
        dp = new boolean[n][n];
        list = new ArrayList<>();

        for (int g = 0; g < n; g++) {
            List<String> newList = new ArrayList<String>();
            for (int i = 0, j = g; j < n; j++, i++) {
                if (g == 0) {
                    dp[i][j] = true;
                } else if (g == 1) {
                    dp[i][j] = arr[i] == arr[j];
                } else {
                    if (arr[i] == arr[j]) {
                        if (dp[i + 1][j - 1]) {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
        solve(s, new ArrayList<String>(), 0);
        return list;
    }
}