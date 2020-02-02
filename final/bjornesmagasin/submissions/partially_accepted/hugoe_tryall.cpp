//only works for n <= 15
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

#define rep(i,a,b) for(ll i = a; i<b;i++)
#define per(i,a,b) for(ll i = a; i>=b; i--)
#define inf LLONG_MAX
#define all(x) x.begin(),x.end()
#define sz(x) (ll)(x).size()
#define trav(a,x) for(auto &a: x)
#define mp(x,y) make_pair(x,y)

ll mth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

ll day(ll m, ll d){
  ll cnt = 0;
  rep(i,0,m){
    cnt += mth[i];
  }
  cnt += d-1;
  return cnt;
}

int main(){
  ll n,d,bj;
  vi bjs;
  cin >> n >> d;
  string s;
  rep(i,0,n){
    cin >> s;
    ll mm = 10*(s[3]-'0') + (s[4]-'0');
    ll dd = 10*(s[0]-'0') + (s[1]-'0');
    if (i == 0) bj = day(mm,dd);
    else bjs.push_back(day(mm,dd));
  }
  n--;
  ll bst = n+1;
  rep(i,0,(1<<n)) {
    ll cnt = 0;
    ll awake[365];
    rep(j,0,365) awake[j] = 0;
    rep(k,0,365-d) awake[(bj+k)%365] = 1;
    rep(j,0,n) if (i&(1<<j)){
      cnt++;
      rep(k,0,365-d) awake[(bjs[j]+k)%365] = 1;
    }
    bool pos = true;
    rep(j,0,365) { if (!awake[j]) { pos = false; break; } }
    if (pos) bst = min(bst,cnt);
  }
  if (bst == n+1) cout << -1 << endl;
  else cout << bst << endl;
}
