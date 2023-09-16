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

bool isok() {
  rep(i,0,N) {
    rep(j,0,M) {
      rep(di,-1,2) rep(dj,-1,2) {
        if (di && dj) continue;
        if (!di && !dj) continue;
        int ni = i + di;
        int nj = j + dj;
        if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
        if (abs(grid[i][j] - grid[ni][nj]) > 1) return false;
      }
    }
  }
  return true;
}

int main() {
	cin >> N >> M;
	grid.resize(N);
	rep(i,0,N) cin >> grid[i];

  vector<vector<vector<bool>>> ok(N, vector<vector<bool>>(M, vector<bool>(256)));

  vector<pii> missing;
  rep(i,0,N) rep(j,0,M) if (grid[i][j] == '.') missing.emplace_back(i,j);
  if (missing.size() != N * M) {
    int mx = 1;
    rep(i,0,missing.size()) mx *= 10;
    rep(i,0,mx) {
      int w = i;
      trav(it, missing) {
        grid[it.first][it.second] = (w % 10) + '0';
        w /= 10;
      }
      if (isok())  {
        trav(it, missing) {
          ok[it.first][it.second][grid[it.first][it.second]] = true;
        }
      }
    }
    trav(it, missing) {
      grid[it.first][it.second] = '.';
      if (count(all(ok[it.first][it.second]), true) == 1) {
        rep(i,0,256) if (ok[it.first][it.second][i]) grid[it.first][it.second] = i;
      }
    }
  }
  trav(it, grid) cout << it << endl;
}

