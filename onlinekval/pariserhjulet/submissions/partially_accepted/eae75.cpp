#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int64_t> teams(N);
	for (int i = 0; i < N; i++)
		cin >> teams[i];
	
	vector<int64_t> availTime(M);
	for (int i = 0; i < M; i++)
		availTime[i] = i;
	
	int64_t ans = 0;
	for (int64_t turns : teams) {
		int nextAvail = 0;
		for (int i = 1; i < M; i++) {
			if (availTime[i] < availTime[nextAvail])
				nextAvail = i;
		}
		
		availTime[nextAvail] += turns * M;
		ans = max(ans, availTime[nextAvail]);
	}
	
	cout << ans << "\n";
}
