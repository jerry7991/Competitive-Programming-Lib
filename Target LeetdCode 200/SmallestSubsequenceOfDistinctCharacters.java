class Solution {
    public String smallestSubsequence(String s) {
        int [] cnt = new int[26];
        boolean[] seen =  new boolean[26];

        char [] arr = s.toCharArray();

        for (char ch : arr) {
            cnt[ch - 'a']++;
        }

        Stack<Character> stack = new Stack<>();

        for (char ch : arr) {
            cnt[ch - 'a']--;

            if (seen[ch - 'a']) continue;

            seen[ch - 'a'] = true;

            while (!stack.isEmpty() && cnt[stack.peek() - 'a'] > 0 && stack.peek() > ch) {
                seen[stack.peek() - 'a'] = false;
                stack.pop();
            }
            stack.push(ch);
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.peek());
            stack.pop();
        }
        sb.reverse();
        return sb.toString();
    }
}