class Solution {


    private int []arr;
    private int []original;

    Random rand  = new Random();

    private int randRange(int min, int max) {
        return rand.nextInt(max - min) + min;
    }

    private void swap(int i, int j) {
        int temp  = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public Solution(int[] nums) {
        arr = nums;
        original = nums.clone();
    }

    public int[] reset() {
        arr = original;
        original = original.clone();
        return original;
    }

    public int[] shuffle() {
        for (int i = 0; i < n; i++) {
            swap(i, randRange(i, arr.length));
        }
    }
}
