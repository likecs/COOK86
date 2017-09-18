// O(n)

import java.util.Scanner;

class B {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int T = 1; T <= t; ++T) {
			int n = in.nextInt();
			for(int i = 1; i <= n; ++i) {
				System.out.print(2*i + " ");
			}
			System.out.println();
		}
		in.close();
	}
}