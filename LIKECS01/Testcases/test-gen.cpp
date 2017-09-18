#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	srand(unsigned(time(NULL)));
	int t = 1000;
	printf("%d\n", t);
	int mod = 100;
	while(t--) {
		int n = rand() % mod + 1;
		if (t%3 == 0) {
			n = rand() % 13 + 1;
		}
		if (t%4 == 0) {
			n = rand() % 26 + 1;
		}
		for(int i = 0; i < n; ++i) {
			printf("%c", rand()%26 + 'a');
		}
		printf("\n");
	}
	return 0;
}