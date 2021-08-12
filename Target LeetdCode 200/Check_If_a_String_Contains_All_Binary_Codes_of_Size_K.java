class Solution {
    public boolean hasAllCodes(String s, int k) {
        Set<String> set = new HashSet();
        int need = 1 << k;
        for (int i = k; i <= s.length(); i++) {
            String st = s.substring(i - k, i);
            if (!set.contains(st)) {
                set.add(st);
                need--;
            }
            if (need == 0) return true;
        }
        return false;
    }
}