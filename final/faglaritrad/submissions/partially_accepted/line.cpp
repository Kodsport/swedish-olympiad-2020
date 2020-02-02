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



int main() {

    cin >> n >> m >> k;

    if(k-m+1 >= 1){
        rep(c1,0,m){
            cout << k-m+1+c1 << " ";
        }cout << "\n";
        return 0;
    }

    if(k+m-1 <= n){
        rep(c1,0,m){
            cout << k+m-1-c1 << " ";
        }cout << "\n";
        return 0;
    }

    cout << "-1\n";

    return 0;
}


