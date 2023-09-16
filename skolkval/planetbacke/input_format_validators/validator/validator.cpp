#include "validator.h"
#include <cmath>

#define sz(v) int(v.size())

void run() {
	int n = Int(1, Arg("n", 7));
	Space();
	int m = Int(1, Arg("m", 7));
	Endl();

	map<char, int> count;
	vector<string> grid(n);
	for(int i = 0; i < n; i++) {
		string str = Line();
		assert(sz(str) == m);
		grid[i] = str;
		for (char c : str) {
			assert(c >= '0' && c <= '9');
			assert(++count[c] <= 7);
		}
	}

	int neighLim = Arg("lim", 8);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++) {
		int same = 0;
		for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++)
		if (di || dj) {
			int ni = i + di;
			int nj = j + dj;
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (grid[i][j] == grid[ni][nj]) same++;
		}
		assert(same <= neighLim);
	}
}
