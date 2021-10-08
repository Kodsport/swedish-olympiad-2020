#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int64_t> teams(N);
	for (int i = 0; i < N; i++)
		cin >> teams[N - i - 1];
	
	vector<int64_t> remTurns(M);
	for (int i = 0; i < M; i++)
		remTurns[i] = 0;
	
	int64_t ans = 0;
	int64_t remTurnsSum = 0;
	size_t bottomIdx = 0;
	while (!teams.empty() || remTurnsSum > 0) {
		if (remTurns[bottomIdx] != 0) {
			remTurns[bottomIdx]--;
			remTurnsSum--;
		}
		if (!teams.empty() && remTurns[bottomIdx] == 0) {
			remTurns[bottomIdx] = teams.back();
			remTurnsSum += teams.back();
			teams.pop_back();
		}
		bottomIdx = (bottomIdx + 1) % M;
		ans++;
	}
	
	cout << (ans - 1) << "\n";
}
