#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(int argc, char const *argv[]) {
	srand(unsigned(time(NULL)));
	int n = atoi(argv[1]);
	int mod = atoi(argv[2]);
	printf("%d\n", n);
	for(int i = 1; i <= n; ++i) {
		int x = rand() % (mod + 1);
		printf("%d%c", x, i < n ? ' ' : '\n');
	}
	return 0;
}