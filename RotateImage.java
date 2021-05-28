import java.util.*;

public class RotateImage {


	//	Using tronspose
	public static void rotate(int[][] matrix) {
		int n = matrix.length, m = matrix[0].length;

		// First let's tronspose the matrix i.e change row to col
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				// Swap [i,j] to [j,i]
				int t = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = t;
			}
		}

		for (int left = 0, right = m - 1; left < right; left++, right--) {
			for (int j = 0; j < n; j++) {
				int t = matrix[j][left];
				matrix[j][left] = matrix[j][right];
				matrix[j][right] = t;
			}
		}

	}


	public static void rotateUsing4Points(int[][] matrix) {
		int n = matrix.length, m = matrix[0].length;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int [][]matrix = new int[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = scan.nextInt();
			}
		}

		rotate(matrix);


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = scan.nextInt();
			}
		}
	}
}