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
    ll n;
    double l;
    cin>>n>>l;
    vector<double> s(n);
    vector<double> c(n);

    rep(i,0,n) cin>>s[i]>>c[i];

    double dn = 1e-6;
    double up = 1e18;

    while(dn+1e-8<up){
        double mid = (dn+up)/2;

        bool fastEnough = true;
        double bikesum = 0;
        rep(i,0,n) {
            if(l>mid*s[i]){
                if(c[i]<=s[i]) fastEnough = false;

                bikesum += (mid-l/s[i])/(1/c[i]-1/s[i]);

            }
        }
        if(bikesum<=l&&fastEnough) up = mid;
        else dn = mid;
    }
    cout<<(dn+up)/2<<endl;
}