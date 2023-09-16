#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi dr = {-1, -1, -1, 0, 1, 1, 1, 0};
vi dc = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int R, C;
  cin >> R >> C;
  vector<string> S(R);
  rep(i,0,R) cin >> S[i];

  vector<vi> A(R, vi(C, 1));
  rep(i,0,R*C) {
    rep(r,0,R) rep(c,0,C) {
      rep(j,0,8) {
        int nr = r + dr[j];
        int nc = c + dc[j];
        if (nr >= 0 && nc >= 0 && nr < R && nc < C && S[r][c] > S[nr][nc]) {
          A[r][c] = max(A[r][c], A[nr][nc] + 1);
        }
      }
    }
  }
  int r = 0;
  for(auto it: A) for(auto it2: it) r = max(r, it2);
  cout << r << endl;
}
