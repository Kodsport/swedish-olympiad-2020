#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int64_t> teamTurns(N);
	for (int i = 0; i < N; i++)
		cin >> teamTurns[i];
	
	priority_queue<int64_t, vector<int64_t>, greater<>> pq;
	for (int i = 0; i < M; i++)
		pq.push(i);
	
	int64_t ans = 0;
	for (int64_t turns : teamTurns) {
		int64_t endTime = pq.top() + turns * M;
		pq.pop();
		pq.push(endTime);
		ans = max(ans, endTime);
	}
	
	cout << ans << "\n";
}
