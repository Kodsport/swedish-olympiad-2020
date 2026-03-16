#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n > 40)
		return 1;
	
	vector<int> conn(n, -1);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		conn[a - 1] = i;
		conn[b - 1] = i;
	}
	
	string ans = "-1";
	
	int8_t dp[42][3];
	for (int s = 0; s < 3; s++)
		dp[n][s] = true;
	
	for (int bm = 0; bm < 1 << m; bm++) {
		for (int i = n - 1; i >= 0; i--) {
			int ot = -1;
			if (conn[i] != -1)
				ot = (bm >> conn[i]) & 1;
			for (int s = 0; s <= 2; s++) {
				if (s != 0 && ot != 1 && dp[i + 1][s - 1])
					dp[i][s] = 1;
				else if (s != 2 && ot != 0 && dp[i + 1][s + 1])
					dp[i][s] = 2;
				else
					dp[i][s] = 0;
			}
		}
		
		if (dp[0][1]) {
			string newAns;
			int s = 1;
			for (int i = 0; i < n; i++) {
				newAns += '0' + dp[i][s];
				s += (int)dp[i][s] * 2 - 3;
			}
			if (ans == "-1" || newAns < ans)
				ans = newAns;
		}
	}
	
	cout << ans << "\n";
}
