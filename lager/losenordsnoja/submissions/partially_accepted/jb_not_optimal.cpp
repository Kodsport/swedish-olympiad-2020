#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tuple<int,int,int>> vt;
typedef vector<vt> vvt;

const int inf = 1e9;
tuple<int,int,int> done = {-1,-1,-1};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int k, la, lb;
  string a,b;
  cin >> k >> a >> la >> b >> lb;
  if(la < lb) swap(la,lb), swap(a,b);

  // [index a, index b, active]
  vector<vvi> dp(sz(a)+1, vvi(sz(b)+1, vi(2, inf)));
  vector<vvt> dad(sz(a)+1, vvt(sz(b)+1, vt(2, done)));

  auto move = [&](int i, int j, int q, int ni, int nj, int nq, int cost=0) {
    // try move [i,j,q] -> [ni,nj,nq]
    if(dp[ni][nj][nq] > dp[i][j][q] + cost) {
      dp[ni][nj][nq] = dp[i][j][q] + cost;
      dad[ni][nj][nq] = {i,j,q};
    }
  };

  dp[0][0][0] = 0;
  rep(i,0,sz(a)+1) rep(j,0,sz(b)+1) {
    move(i,j,0, i,j,1);
    if(lb-j <= la-i) move(i,j,1, i,j,0, la-i); // BUG HERE: should be lb-j
    if(i < sz(a) && j < sz(b) && a[i] == b[j]) move(i,j,0, i+1,j+1,0);
    if(i < sz(a)) move(i,j,1, i+1,j,1);
  }

  // reconstruct solution
  int i = sz(a), j = sz(b), q = 0, ni, nj, nq;
  int s = dp[i][j][q];

  if(s == inf) {
    cout << "!" << endl;
    return 0;
  }

  vt trans = {{i,j,q}};
  while(trans.back() != done) {
    tie(i,j,q) = trans.back();
    trans.emplace_back(dad[i][j][q]);
  }
  trans.pop_back();
  reverse(all(trans));

  string ans;
  trav(t, trans) {
    tie(ni,nj,nq) = t;
    if(q-nq == 1) ans += string((lb-j), 'q') + string((lb-j), '<');
    if(ni == i+1) ans += a[i];
    tie(i,j,q) = t;
  }
  //assert(sz(ans) == s + sz(a));
  cout << ans << endl;
}
