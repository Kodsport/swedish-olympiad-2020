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

    ll ind = 0;
    ll ans = 0;
    ll read = 0;
    while(true){
        if(wheel[ind]>0)
            wheel[ind]--;
        if(wheel[ind]==0) {
            if(read<n){
                read++;
                cin>>wheel[ind];
            } else {
                ll ad = 0;
                rep(i,0,m) ad = max(ad,m*(wheel[i]-1)+((i-ind+m)%m));
                ans+=ad;
                break;
            }
        }
        
        ll mn = 1e18;
        rep(i,0,m) mn = min(mn,wheel[i]);
        if(mn>1){
            rep(i,0,m) wheel[i]-=mn-1;
            ans+=m*(mn-1);
        }
        ans++;
        ind = (ind+1)%m;
    }
    cout<<ans<<endl;
    
}