#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	srand(unsigned(time(NULL)));
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	printf("%d %d\n", n, m);
	vector<pair<int,pair<int,int>>> ans;
	for(int i = 1; i <= m; ++i) {
		int idx;
		int type;
		int color = rand() % 2;
		if (i <= m/5) {
			type = 1;
		}
		else if (i <= 3*m/5) {
			type = 2;
		}
		else {
			type = 3;
		}
		if (type == 1) {
			idx = rand() % n + 1;
		}
		else if (type == 2) {
			idx = rand() % n + 1;
		}
		else {
			idx = rand() % (2 * n - 1) + 2;
		}
		ans.push_back({type, {idx, color}});
	}
	random_shuffle(ans.begin(), ans.end());
	for(auto it : ans) {
		printf("%d %d %d\n", it.first, it.second.first, it.second.second);
	}
	return 0;
}