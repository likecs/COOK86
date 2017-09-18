#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	srand(unsigned(time(NULL)));
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int mod = atoi(argv[3]);
	mod = min(mod, 1 << k);
	printf("%d %d\n", n, k);
	for(int i = 0; i < n; ++i) {
		int x = rand() % mod;
		printf("%d%c", x, i == n-1 ? '\n' : ' ');
	}
	return 0;
}