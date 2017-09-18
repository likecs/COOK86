// O(n * bmax^2 * sumb)

import java.util.Scanner;

class D {
	static int MAX = 51;
	static int MAX2 = 2501;
	static int MOD = 1000000007;

	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int b[] = new int[n+1];
		for(int i = 1; i <= n; ++i) {
			b[i] = in.nextInt();
		}
		int pre[][] = new int[MAX][MAX];
		for(int i = 0; i < MAX; ++i) {
			for(int j = 0; j < MAX; ++j) {
				pre[i][j] = gcd(i, j);
			}
		}
		int dp[][][] = new int[n+1][MAX][MAX2];
		for(int i = 0; i <= b[1]; ++i) {
			dp[1][i][i] = 1;
		}
		for(int pos = 1; pos < n; ++pos) {
			for(int x = 0; x < MAX; ++x) {
				for(int y = 0; y <= b[pos+1]; ++y) {
					for(int s = 0; s + y < MAX2; ++s) {
						int z = pre[x][y];
						dp[pos+1][z][s + y] += dp[pos][x][s];
						dp[pos+1][z][s + y] %= MOD;
					}
				}
			}
		}
		int ans = 0;
		for(int g = 1; g < MAX; ++g) {
			for(int s = 1; s * g < MAX2; s *= 2) {
				ans += dp[n][g][s * g];
				ans %= MOD;
			}
		}
		System.out.println(ans);
	}

	static int gcd(int a, int b) {
		while(b > 0) {
			int c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
}