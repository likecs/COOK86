// O(n + k)

import java.util.Scanner;

class C {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int T = 1; T <= t; ++T) {
			int n = in.nextInt();
			int k = in.nextInt();
			int mark[] = new int[1 << k];
			for(int i = 1; i <= n; ++i) {
				int x = in.nextInt();
				if (x > 0 && (x & (x-1)) == 0) {
					mark[x] = 1;
				}
			}
			int ans = k;
			for(int i = 0; i < k; ++i) {
				ans -= mark[1 << i];
			}
			System.out.println(ans);
		}
		in.close();
	}
}