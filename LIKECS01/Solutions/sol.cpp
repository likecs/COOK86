// O(|S|)

#include <bits/stdc++.h>
using namespace std;

const int ALPHA = 26;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		vector<int> freq(ALPHA, 0);
		for(int i = 0; i < s.length(); ++i) {
			freq[s[i] - 'a'] += 1;
		}
		bool ans = 0;
		for(int i = 0; i < ALPHA; ++i) {
			ans |= (freq[i] > 1);
		}
		if (ans) {
			puts("yes");
		}
		else {
			puts("no");
		}
	}
	return 0;
}