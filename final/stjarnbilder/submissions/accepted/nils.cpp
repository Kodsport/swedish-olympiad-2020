#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 300001;
const ll inv = 500000004;

vector<pll> P;
map<ll,ll> M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        cin >> a >> b;
        P.push_back({a,b});
    }
    ll ma = 0;
    rep(c1,0,n){
        cin >> a >> b;
        rep(c2,0,n){
            c = (a-P[c2].first)*10000000 + (b-P[c2].second);
            M[c]++;
            ma = max(ma, M[c]);
        }
    }
    cout << n - ma << "\n";

    return 0;
}



