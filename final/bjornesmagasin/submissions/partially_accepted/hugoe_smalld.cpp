//only works for d <= 182
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
  rep(i,0,n){
    ll tmp = (bj-bjs[i]+365)%365;
    if (tmp >= d && tmp <= 365-d) { cout << 1 << endl; exit(0); }
  }
  int awake[365];
  rep(i,0,365) awake[i] = 0;
  rep(k,0,365-d) awake[(bj+k)%365] = 1;
  rep(i,0,n) rep(k,0,365-d) awake[(bjs[i]+k)%365] = 1;
  rep(i,0,365) if (!awake[i]) { cout << -1 << endl; exit(0); }
  cout << 2 << endl;

}
