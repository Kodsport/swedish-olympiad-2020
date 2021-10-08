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
    string str;
    cin>>str;
    ll n = sz(str);
    ll s = 0;
    rep(i,0,n/2) s+=(str[i]=='B');

    ll ans = 0;
    rep(i,0,n-1){
        s-=(str[i]=='B');
        s+=(str[(i+n/2)%n]=='B');
        ans = max(ans,s);
    }
    cout<<ans<<endl;
}