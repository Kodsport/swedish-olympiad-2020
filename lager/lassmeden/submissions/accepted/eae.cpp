#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	
	constexpr int SQRT_N = 350;
	
	vector<int> countBigMod(N + 1, 0);
	unordered_map<int, int> countSmallMod[SQRT_N];
	
	for (int q = 0; q < Q; q++) {
		int type, x;
		cin >> type >> x;
		
		if (type == 1) {
			bool ans = countBigMod[x] > 0;
			for (int m = 1; m < SQRT_N; m++) {
				if (countSmallMod[m][x % m]) {
					ans = true;
					break;
				}
			}
			
			cout << (ans ? "ja" : "nej") << "\n";
		} else {
			int m;
			cin >> m;
			int delta = type == 2 ? 1 : -1;
			
			if (m < SQRT_N) {
				countSmallMod[m][x] += delta;
			} else {
				for (int i = x; i <= N; i += m) {
					countBigMod[i] += delta;
				}
			}
		}
	}
}
