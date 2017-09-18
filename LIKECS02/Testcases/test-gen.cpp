#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	srand(unsigned(time(NULL)));
	int t = 10;
	printf("%d\n", t);
	int mod = atoi(argv[1]);
	while(t--) {
		int n = rand() % mod + 1;
		printf("%d\n", n);
	}
	return 0;
}