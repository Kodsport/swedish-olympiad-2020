#include "validator.h"
#include <set>
using namespace std;

int solve(vector<pair<int, int>> points[]) {
	vector<pair<int, int>> deltas;
	for (auto p1 : points[0]) {
		for (auto p2 : points[1]) {
			deltas.emplace_back(p1.first - p2.first, p1.second - p2.second);
		}
	}
	
	sort(deltas.begin(), deltas.end());
	
	int maxStars = 0;
	for (int i = 0; i < (int) deltas.size();) {
		int ed = i + 1;
		while (ed < (int) deltas.size() && deltas[ed] == deltas[ed - 1])
			ed++;
		maxStars = max(maxStars, ed - i);
		i = ed;
	}
	
	return (int) points[0].size() - maxStars;
}

void run() {
	int nMax = Arg("nMax");
	int ansMax = Arg("ansMax", nMax);
	
	constexpr int MAX_ABS_COORD = 1000000;
	
	int n = Int(1, nMax);
	Endl();
	
	vector<pair<int, int>> points[2];
	for (int t = 0; t < 2; t++) {
		set<pair<int, int>> seen;
		for (int i = 0; i < n; i++) {
			int x = Int(-MAX_ABS_COORD, MAX_ABS_COORD);
			Space();
			int y = Int(-MAX_ABS_COORD, MAX_ABS_COORD);
			Endl();
			
			if (!seen.emplace(x, y).second) {
				die("Points are not unique");
			}
		}
		points[t] = { seen.begin(), seen.end() };
	}
	
	if (solve(points) > ansMax) {
		die("Answer is too big");
	}
}
