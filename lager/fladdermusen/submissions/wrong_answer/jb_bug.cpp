#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll clamp(ll x, ll a, ll b) {
  if(x < a) x = a;
  if(x > b) x = b;
  return x;
}

struct T {
  ll cost = 0;
  ll open = true;
  ll lh = -1, rh = -1;
  ll down = 0, up = 1e9;
} constexpr unit;

T f(T a, T b) {
  T res;
  res.cost = a.cost + b.cost;
  res.lh = a.lh;
  res.rh = b.rh;
  res.open = a.open && b.open;
  if(a.open && b.open) {
    res.down = max(a.down, b.down);
    res.up = min(a.up, b.up);
    if(res.down >= res.up) {
      res.open = false;
      if(a.down > b.up) {
        res.lh = a.down;
        res.rh = b.up;
        res.cost += abs(res.lh - res.rh);
      }
      else {
        res.lh = a.up;
        res.rh = b.down;
        res.cost += abs(res.lh - res.rh);
      }
    }
  }
  if(!a.open && b.open) {
    res.rh = clamp(a.rh, b.down, b.up);
    res.cost += abs(res.rh - a.rh);
  }
  if(a.open && !b.open) {
    res.lh = clamp(b.lh, a.down, a.up);
    res.cost += abs(res.lh - b.lh);
  }
  if(!a.open && !b.open) {
    res.cost += abs(b.lh - a.rh);
  }
  return res;
}

struct Tree {
  vector<T> s; int n;
  Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) {
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n,q,H,W;
  cin>>n>>q>>H>>W;

  map<ll,T> xs;
  map<ll,int> idx;
  rep(i,0,n) {
    int t,x,y;
    cin>>t>>x>>y;
    T q;
    q.up = H;
    if(t == 1) q.down = y;
    if(t == 2) q.up = y;
    xs[x] = q;
  }
  xs[-1e9] = unit;
  xs[2e9] = unit;

  Tree st(n+2);
  int cnt = 0;
  trav(p, xs) {
    idx[p.first] = cnt;
    st.update(cnt, p.second);
    ++cnt;
  }
  assert(cnt == n+2);

  rep(i,0,q) {
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1 > x2) swap(x1,x2), swap(y1,y2);
    int L = idx.upper_bound(x1)->second;
    int R = idx.upper_bound(x2)->second;
    T res = st.query(L, R);
    T left; left.up = left.down = y1;
    T right; right.up = right.down = y2;
    res = f(left, f(res, right));
    ll ans = res.cost + abs(x2-x1);
    cout << ans << endl;
  }
}
