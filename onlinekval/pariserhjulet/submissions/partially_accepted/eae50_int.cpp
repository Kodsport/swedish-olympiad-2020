//Same as 100pt solution but with int, should get 50pts

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int> teamTurns(N);
	for (int i = 0; i < N; i++)
		cin >> teamTurns[i];
	
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < M; i++)
		pq.push(i);
	
	int ans = 0;
	for (int turns : teamTurns) {
		int endTime = pq.top() + turns * M;
		pq.pop();
		pq.push(endTime);
		ans = max(ans, endTime);
	}
	
	cout << ans << "\n";
}
