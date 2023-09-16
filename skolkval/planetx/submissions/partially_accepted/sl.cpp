#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, M;
vector<string> grid;
vector<string> mins;
vector<string> maxs;

void rec() {
	int ti = -1, tj = -1, mmi = -1, mma = -1, best = 100;
	rep(i,0,N) rep(j,0,M) {
		if (grid[i][j] != '.') continue;
		int mi = 0, ma = 9;
		rep(di,-1,2) rep(dj,-1,2) {
			if (di && dj) continue;
			if (!di && !dj) continue;
			int ni = i + di;
			int nj = j + dj;
			if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
			if (grid[ni][nj] != '.') {
				mi = max(mi, grid[ni][nj] - '0' - 1);
				ma = min(ma, grid[ni][nj] - '0' + 1);
			}
		}
		if (ma - mi < best) {
			best = ma - mi;
			mmi = mi;
			mma = ma;
			ti = i;
			tj = j;
		}
	}

	if (best == 100) {
		rep(i,0,N) rep(j,0,M) {
			mins[i][j] = min(mins[i][j], grid[i][j]);
			maxs[i][j] = max(maxs[i][j], grid[i][j]);
		}
	} else {
		for (int d = mmi; d <= mma; d++) {
			grid[ti][tj] = (char)('0' + d);
			rec();
		}
		grid[ti][tj] = '.';
	}
}

int main() {
	cin >> N >> M;
	grid.resize(N);
	mins.assign(N, string(M, '9'));
	maxs.assign(N, string(M, '0'));
	rep(i,0,N) cin >> grid[i];
	rec();
	rep(i,0,N) {
		rep(j,0,M) {
			if (mins[i][j] == maxs[i][j]) cout << mins[i][j];
			else cout << '.';
		}
		cout << endl;
	}
}
