// O(n logn)

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, k, x, ans;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		vector<int> v;
		for(int i = 0; i < n; ++i) {
			cin >> x;
			if (x > 0 && ((x & (x-1)) == 0)) {
				v.push_back(x);
			}
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		ans = k - (int)v.size();
		cout << ans << "\n";
	}
	return 0;
}