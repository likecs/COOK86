#include "spoj.h"
#include <stdlib.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 105;

int inp[MAX];
long long a[MAX];

int main(int argc, char const *argv[]) {
	spoj_init();

	//read problem input.
	int t, n;
	fscanf(spoj_p_in, "%d", &t);
	for(int i = 0; i < t; ++i) {
		fscanf(spoj_p_in, "%d", &inp[i]);
	}

	//read user output.
	bool correct = 1;
	for(int i = 0; i < t; ++i) {
		int n = inp[i];
		set<long long> nums;
		bool pos = 1;
		for(int i = 0; i < n; ++i) {
			fscanf(spoj_t_out, "%lld", &a[i]);
			pos &= (a[i] > 0 && a[i] <= 1000000000);
			nums.insert(a[i]);
		}
		if (pos == 0 || nums.size() < n) {
			correct = 0;
			break;
		}

		//ensure no round off error due to doubles.
		long long ans = 0, half = 0;
		for(int i = 0; i < n; ++i) {
			vector<long long> x;
			for(int j = i; j < n; ++j) {
				x.push_back(a[j]);
				sort(x.begin(), x.end());
				if (x.size() % 2 == 1) {
					ans += x[x.size()/2];
				}
				else {
					int l = x[x.size()/2-1];
					int r = x[x.size()/2];
					if ((l+r)%2 == 1) {
						half += 1;
					}
					ans += (l+r)/2;
				}
			}
		}
		ans = ans * 2 + half;
		long long den = n * (n + 1);
		if (den * (n-1) <= ans && ans <= den * (n+1)) {
			//
		}
		else {
			correct = 0;
			break;
		}
	}

	if (correct) {
		return SPOJ_RV_POSITIVE;
	}
	else {
		return SPOJ_RV_NEGATIVE;
	}

	return 0;
}