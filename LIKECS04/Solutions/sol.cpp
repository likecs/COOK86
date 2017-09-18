// O(n * bmax^2 * sumb)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAX = 51;
const int MAX2 = 51 * 51;
const int MOD = 1e9 + 7;

int n;
int b[MAX];
int pre[MAX][MAX];
int dp[MAX][MAX][MAX2];

int gcd(int a, int b) {		//to avoid runtime error in calling __gcd(0, 0)
	return (b ? __gcd(a, b) : a);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < MAX; ++j) {
			pre[i][j] = gcd(i, j);
		}
	}
	for(int i = 0; i <= b[1]; ++i) {
		dp[1][i][i] = 1;
	}
	for(int pos = 1; pos < n; ++pos) {
		for(int x = 0; x < MAX; ++x) {
			for(int y = 0; y <= b[pos+1]; ++y) {
				for(int s = 0; s+y < MAX2; ++s) {
					int z = pre[x][y];
					dp[pos+1][z][s + y] += dp[pos][x][s];
					if (dp[pos+1][z][s + y] > MOD) {
						dp[pos+1][z][s + y] -= MOD;
					}
				}
			}
		}
	}
	int ans = 0;
	for(int g = 1; g < MAX; ++g) {
		for(int s = 1; g * s < MAX2; s *= 2) {
			ans += dp[n][g][g * s];
			if (ans >= MOD) {
				ans -= MOD;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}