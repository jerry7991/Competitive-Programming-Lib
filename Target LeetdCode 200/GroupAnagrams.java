class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> list = new ArrayList<>();
        Map<String, ArrayList<Integer>> map = new HashMap<>();

        int j = 0;
        for (String str : strs) {
            int []freq = new int[26];
            for (int i = 0; i < str.length(); i++) freq[str.charAt(i) - 'a']++;

            StringBuilder key  = new StringBuilder();
            for (int i : freq) key.append(i + "$");

            String k = key.toString();

            ArrayList<Integer> temp = map.get(k);
            if (temp == null) {
                temp = new ArrayList<Integer>();
            }
            temp.add(j++);
            map.put(k, temp);
        }

        for ( List<Integer> entry : map.values()) {
            ArrayList<String> lst = new ArrayList<String>();
            for (Integer i : entry) lst.add(strs[i]);
            list.add(lst);
        }
        return list;
    }
}