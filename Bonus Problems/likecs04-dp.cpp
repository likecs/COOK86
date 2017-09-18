/*
Fix a particular value of gcd.
Precompute what pairs give that value.
For that particular value of gcd & given choices of b[i]
iterate over what other possible number can be
and also the sum (3rd dimension) in steps gcd
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAX = 51;
const int MAX2 = 51 * 51;
const int MOD = 1e9 + 7;

int n;
int b[MAX];
vector<int> pre[MAX][MAX];
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
			pre[gcd(i, j)][i].push_back(j);
		}
	}
	for(int i = 0; i <= b[1]; ++i) {
		dp[1][i][i] = 1;
	}

	int sum = b[1];
	for(int pos = 1; pos < n; ++pos) {
		sum += b[pos+1];
		for(int g = 0; g < MAX; ++g) {
			for(int y = 0; y <= b[pos+1]; y += max(1, g)) {
				for(int x : pre[g][y]) {
					for(int s = 0; s <= sum; s += max(1, g)) {
						dp[pos+1][g][s + y] += dp[pos][x][s];
						if (dp[pos+1][g][s + y] >= MOD) {
							dp[pos+1][g][s + y] -= MOD;
						}
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