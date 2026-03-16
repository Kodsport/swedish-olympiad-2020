#include <bits/stdc++.h>
using namespace std;

vector<int> color;
vector<vector<pair<int, bool>>> edges;

void dfs(int n, int c) {
	if (color[n] == -1) {
		color[n] = c;
		for (auto e : edges[n]) {
			auto [next, same] = e;
			dfs(next, same ? c : 1 - c);
		}
	} else if (color[n] != c) {
		cout << "-1\n";
		exit(0);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int nPairs = (n + 1) / 2;
	
	color.resize(nPairs, -1);
	edges.resize(nPairs);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		bool same = b % 2 == a % 2;
		edges[b / 2].emplace_back(a / 2, same);
		edges[a / 2].emplace_back(b / 2, same);
	}
	
	for (int i = 0; i < nPairs; i++) {
		if (color[i] == -1)
			dfs(i, 0);
	}
	
	for (int i = 0; i < nPairs; i++) {
		const char* s = color[i] ? "21" : "12";
		if (i * 2 + 1 == n)
			cout << s[0];
		else
			cout << s;
	}
	cout << "\n";
}
