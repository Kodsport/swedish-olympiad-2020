//full solution
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
    else bjs.push_back((365+day(mm,dd)-bj)%365);
  }
  n--;
  sort(all(bjs));
  ll cnt = 0,lst = 0,cur = 0;
  while(true){
    while(cur < n && bjs[cur] <= lst+365-d) cur++;
    cnt++;
    if (bjs[cur-1] == lst) {cout << -1 << endl; exit(0); }
    if (bjs[cur-1]+365-d >= 365) {cout << cnt << endl; exit(0); }
    lst = bjs[cur-1];
  }
}
