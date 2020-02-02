#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> points1(n);
	vector<pair<int, int>> points2(n);
	for (int i = 0; i < n; i++) {
		cin >> points1[i].first >> points1[i].second;
	}
	for (int i = 0; i < n; i++) {
		cin >> points2[i].first >> points2[i].second;
	}

	vector<pair<int, int>> deltas;
	int maxStars = 0;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			deltas.emplace_back(points1[a].first - points2[b].first, points1[a].second - points2[b].second);
		}
	}

	sort(deltas.begin(), deltas.end());
	for (int i = 0; i < (int) deltas.size();) {
		int ed = i + 1;
		while (ed < (int) deltas.size() && deltas[ed] == deltas[ed - 1])
			ed++;
		maxStars = max(maxStars, ed - i);
		i = ed;
	}

	cout << n - maxStars << "\n";
}
