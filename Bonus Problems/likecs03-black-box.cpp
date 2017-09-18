/*
Use the idea that if a bit is to be set, it will be in maximum
K steps of recursion. Thus, instead of doing subset OR we can
simply perform pairwise OR and do it K times.

To get the complexity as mentioned in editorial i.e. O(2^k logn)
you can first read about OR convultions from this blog
https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it/
So, instead of marking the values as 1 in previous solution, we simply
add 1 and simply find number of subsets with OR of elements as "X". This
is standard problem described in the above blog.
(example is with AND operation)
*/

#include <bits/stdc++.h>
using namespace std;

int N, K, REQ;
vector<int> a, mark;

// Complexity : O(K * 4^K)
void run() {
	for(int k = 0; k < K; ++k) {
		for(int i = 0; i < REQ; ++i) {
			for(int j = 0; j < REQ; ++j) {
				if (mark[i] && mark[j]) {
					mark[i|j] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> N >> K;
	REQ = 1 << K;
	a.resize(N);
	mark.resize(REQ);
	mark[0] = 1;
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
		mark[a[i]] = 1;
	}
	run();
	for(int i = 0; i < REQ; ++i) {
		if (mark[i]) {
			cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}