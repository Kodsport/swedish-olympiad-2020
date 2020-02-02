#pragma GCC optimize("Ofast")
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
	
	sort(points2.begin(), points2.end());
	
	int maxStars = 0;
	for (auto p1 : points1) {
		for (auto p2 : points2) {
			int dx = p2.first - p1.first;
			int dy = p2.second - p1.second;
			int numSt = 0;
			for (auto p3 : points1) {
				int nx = p3.first + dx;
				int ny = p3.second + dy;
				auto it = lower_bound(points2.begin(), points2.end(), make_pair(nx, ny));
				if (it != points2.end() && it->first == nx && it->second == ny)
					numSt++;
			}
			maxStars = max(maxStars, numSt);
		}
	}
	
	cout << n - maxStars << "\n";
}
