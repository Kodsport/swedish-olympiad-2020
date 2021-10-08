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

    vi wheel(m);

    ll i = 0;
    ll ans = 0;
    ll read = 0;
    ll done = 0;
    while(done<m){
        if(wheel[i]==0) {
            if(read<n){
                read++;
                cin>>wheel[i];
            } else done++;
        }
        wheel[i]--;
        ans++;
        i = (i+1)%m;
    }
    cout<<ans-1<<endl;
    
}