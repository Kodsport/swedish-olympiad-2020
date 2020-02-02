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
	
	map<pair<int, int>, int> freq;
	int maxStars = 0;
	for (auto p1 : points1) {
		for (auto p2 : points2) {
			maxStars = max(maxStars, ++freq[make_pair(p1.first - p2.first, p1.second - p2.second)]);
		}
	}
	
	cout << n - maxStars << "\n";
}
