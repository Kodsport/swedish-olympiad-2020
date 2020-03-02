#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template<class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T>& V) {
    int N = sz(V), on = 1, depth = 1;
    while (on < N) on *= 2, depth++;
    jmp.assign(depth, V);
    rep(i,0,depth-1) rep(j,0,N)
      jmp[i+1][j] = max(jmp[i][j],
          jmp[i][min(N - 1, j + (1 << i))]);
  }
  T query(int a, int b) {
    assert(a < b);
    int dep = 31 - __builtin_clz(b - a);
    return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};


int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  ll n,q,h,w;
  cin>>n>>q>>h>>w;
  map<ll,ll> xs, typ1, typ2;
  rep(i,0,n) {
    int t,x,y;
    cin>>t>>x>>y;
    xs[x] = -1;
    if(t == 1) typ1[x] = y;
    if(t == 2) typ2[x] = y;
  }
  vector<tuple<int,int,int,int> > queries;
  rep(i,0,q) {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    queries.emplace_back(a,b,c,d);
    xs[a] = xs[c] = -1;
  }
  xs[-2e9] = -1;
  xs[+2e9] = -1;

  int cnt = 0;
  trav(p, xs) p.second = cnt++;
  vector<ll> v(cnt,0), nxt2(cnt+1,cnt), xs_inv(cnt), h2(cnt);
  trav(p, xs) xs_inv[p.second] = p.first;
  trav(p, typ1) v[xs[p.first]] = p.second;
  RMQ<ll> rmq(v);
  for(int i = cnt; i-->0; ) {
    nxt2[i] = nxt2[i+1];
    if(typ2.count(xs_inv[i])) {
      nxt2[i] = i;
      h2[i] = typ2[xs_inv[i]];
    }
  }


  trav(Q, queries) {
    int x1, y1, x2, y2;
    tie(x1, y1, x2, y2) = Q;
    if(x1 > x2) swap(x1, x2), swap(y1, y2);
    ll ans = x2-x1, x = xs[x1], x_end = xs[x2], h = y1;
    while(x <= x_end) {
      ll l = x, r = min(nxt2[x], x_end);

      // move from l to r-1
      ll height = rmq.query(l,r+1);
      if(h < height) {
        ans += height - h;
        h = height;
      }

      // move from r-1 to r
      if(r != x_end) { // maybe move down
        height = h2[r];
        if(h > height) {
          ans += h - height;
          h = height;
        }
      }
      else { // final move
        ans += abs(h - y2);
        h = y2;
      }
      x = r+1;
    }
    cout << ans << endl;
  }
}




