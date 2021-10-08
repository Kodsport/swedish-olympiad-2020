#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector< vector<ll> > vii;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(a) a.begin(),a.end()
#define sz(a) (ll) (a).size()
#define pb push_back
const ll inf = 90000000000;
const ll mod = 1000000009;
ll max(ll a, ll b){if(a>b) return a; else return b;}

int main(){
    ll n; cin >> n;
    rep(i,0,n){
        ll m; cin >> m;
        rep(j,0,m){
            ll neigh_j; cin >> neigh_j;
        }
    }
    if (n % 2 == 1) cout << n/2 + 1 << endl;
    else cout << n/2 << endl;
}
