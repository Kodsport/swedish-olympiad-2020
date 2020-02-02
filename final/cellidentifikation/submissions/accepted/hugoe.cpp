#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

ll to_dec(string s){
  ll ans = 0;
  rep(i,0,sz(s)){
    ans *= 2;
    ans += s[i]-'0';
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) << fixed;

  ll n,k,q; cin >> n >> k;
  string s;
  vi mi,ma;
  mi.assign((1<<k),n);
  ma.assign((1<<k),-1);

  rep(i,0,n){
    cin >> s;
    ll tmp = to_dec(s);
    mi[tmp] = min(mi[tmp],i);
    ma[tmp] = max(ma[tmp],i);
  }

  per(i,(1<<k)-1,0){
    rep(j,0,k){
      ma[i] = max(ma[i], ma[i|(1<<j)]);
      mi[i] = min(mi[i], mi[i|(1<<j)]);
    }
  }

  cin >> q;
  rep(i,0,q){
    cin >> s;
    ll tmp = to_dec(s);
    if (mi[tmp] == ma[tmp]) cout << mi[tmp]+1 << "\n";
    else if (mi[tmp] < ma[tmp]) cout << "vet ej" << "\n";
    else cout << "finns ej" << "\n";
  }

}
