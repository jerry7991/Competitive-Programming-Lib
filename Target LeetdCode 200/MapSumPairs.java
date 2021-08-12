class Trie {
    Trie [] node;
    int val;
    Trie(int val) {
        node = new Trie[26];
        for (int i = 0; i < 26; i++) node[i] = null;
        this.val = val;
    }
}

class MapSum {

    Trie node;

    public MapSum() {
        node = new Trie(0);
    }

    public void insert(String key, int val) {
        char [] k = key.toCharArray();
        Trie temp = node;
        for (char ch : k) {
            if (temp.node[ch - 'a'] == null) {
                temp.node[ch - 'a'] = new Trie(0);
            }
            temp = temp.node[ch - 'a'];
        }
        temp.val = val;
    }

    public int sum(String prefix) {
        char []pref = prefix.toCharArray();
        Trie temp = node;
        for (char ch : pref) {
            if (temp.node[ch - 'a'] == null) {
                return 0;
            }
            temp = temp.node[ch - 'a'];
        }
        return doDfs(temp);
    }

    private int doDfs(Trie root) {
        if (root == null) {
            return 0;
        }
        int ans = root.val;
        for (int i = 0; i < 26; i++) {
            ans += doDfs(root.node[i]);
        }
        return ans;
    }


}
