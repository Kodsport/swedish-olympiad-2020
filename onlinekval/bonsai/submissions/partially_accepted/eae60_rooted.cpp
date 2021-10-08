#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int subtreeTime(int node, int par) {
	vector<int> childDelay;
	for (int child : adj[node]) {
		if (child == par)
			continue;
		childDelay.push_back(subtreeTime(child, node));
	}
	sort(childDelay.begin(), childDelay.end(), greater<>());
	int ans = 0;
	for (int i = 0; i < (int)childDelay.size(); i++)
		ans = max(ans, childDelay[i] + i + 1);
	return ans;
}

int main() {
	int n;
	cin >> n;
	adj.resize(n);
	
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		adj[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> adj[i][j];
		}
	}
	
	cout << subtreeTime(0, -1) << "\n";
}
