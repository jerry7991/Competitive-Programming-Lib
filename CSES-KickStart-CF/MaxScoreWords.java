class Solution {

    private int solve(String []words, int i, int [] cntLetter, int []score) {
        if (i == words.length) {
            return 0;
        }

        int []newCnt = cntLetter.clone();

        //  Will tell that whether we can take current word or not
        boolean ableToForm = true;

        //  If we'll be able to take this word then what will be the score
        int formedValue = 0;

        for (int j = 0; j < words[i].length() &&  ableToForm; j++) {
            ableToForm = ableToForm && (--newCnt[words[i].charAt(j) - 'a'] >= 0);
            formedValue += score[words[i].charAt(j) - 'a'];
        }


        //  We have 2 choice for any i-th
        int take = 0, ignore = 0;

        // Either I can take it.
        if (ableToForm) {
            take = formedValue + solve(words, i + 1, newCnt, score);
        }

        //  Or I will have always a way to ignore it.
        ignore = solve(words, i + 1, cntLetter, score);
        return Math.max(take, ignore);
    }

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int []cntLetter = new int[26];
        for (char letter : letters) {
            cntLetter[letter - 'a']++;
        }
        return solve(words, 0, cntLetter, score);
    }
}