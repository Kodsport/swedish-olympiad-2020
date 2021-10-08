#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")

using namespace std;

#define rep(i, a, b) for(ll i = a; i < ll(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    ll n,m;
    cin>>n>>m;
    
    ll ans = 0;
    priority_queue<ll> q;
    rep(i,0,m) q.push(-i);
    rep(i,0,n){
        ll x; cin>>x;
        ll nw = q.top()-x*m;
        ans = max(ans,-nw);
        q.pop();
        q.push(nw);
    }
    cout<<ans<<endl;
}