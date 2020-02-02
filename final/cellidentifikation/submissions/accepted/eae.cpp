#include <bits/stdc++.h>
using namespace std;

constexpr int NONE = 0;
constexpr int MANY = -1;

int dp[22][1 << 21];

int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		string partsS;
		cin >> partsS;
		int parts = stoi(partsS, nullptr, 2);
		if (dp[k][parts] == NONE)
			dp[k][parts] = i + 1;
		else
			dp[k][parts] = MANY;
	}
	
	for (int i = k - 1; i >= 0; i--) {
		for (int p = 0; p < 1 << k; p++) {
			dp[i][p] = dp[i + 1][p];
			if (!(p & (1 << i))) {
				if (int ans2 = dp[i + 1][p | (1 << i)]) {
					if (dp[i][p] == NONE && ans2 != MANY)
						dp[i][p] = ans2;
					else
						dp[i][p] = MANY;
				}
			}
		}
	}
	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		string partsS;
		cin >> partsS;
		int a = dp[0][stoi(partsS, nullptr, 2)];
		if (a == MANY) {
			cout << "vet ej\n";
		} else if (a == NONE) {
			cout << "finns ej\n";
		} else {
			cout << a << "\n";
		}
	}
}
