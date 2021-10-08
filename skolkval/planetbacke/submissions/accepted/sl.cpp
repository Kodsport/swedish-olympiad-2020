#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
typedef long long ll;

int N, M;
vector<string> grid;

map<tuple<int, int, ll>, int> memo;
int rec(int y, int x, ll mask) {
	int& out = memo[make_tuple(y, x, mask)];
	if (out) return out;
	int res = 0;
	rep(dx,-1,2) rep(dy,-1,2) {
		int ny = y + dy;
		int nx = x + dx;
		if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;
		if (grid[ny][nx] > grid[y][x]) continue;
		ll mask2 = grid[ny][nx] < grid[y][x] ? 0 : mask;
		mask2 |= 1LL << (ny * 8 + nx);
		if (mask == mask2) continue;
		res = max(res, rec(ny, nx, mask2));
	}
	return out = res + 1;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N >> M;
	grid.resize(N);
	rep(i,0,N) cin >> grid[i];
	int res = 0;
	rep(i,0,N) rep(j,0,M) res = max(res, rec(i, j, 1LL << (i * 8 + j)));
	cout << res << endl;
}
