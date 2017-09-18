#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	srand(unsigned(time(NULL)));
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	printf("%d %d\n", n, m);
	for(int i = 1; i <= m; ++i) {
		int idx;
		int type = rand() % 3 + 1;
		int color = rand() % 2;
		if (type == 1) {
			idx = rand() % n + 1;
		}
		else if (type == 2) {
			idx = rand() % n + 1;
		}
		else {
			idx = rand() % (2 * n - 1) + 2;
		}
		printf("%d %d %d\n", type, idx, color);
	}
	return 0;
}