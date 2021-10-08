#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

set<ll> E;
vector<vi> C(MAXN, vi());
bool taken[MAXN] = {0};
set<ll> people;

int get_next(int prev){
    if(prev == -1){
        return *(people.begin());
    }
    int a = *(people.begin());
    trav(y, C[prev]){
        if(people.find(y) != people.end())a = y;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    cin >> n >> m;
    rep(c1,0,4*n){
        people.insert(c1);
    }
    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        E.insert(a*4*n+b);
        E.insert(b*4*n+a);
        C[a].push_back(b);
        C[b].push_back(a);
    }

    ll prev = -1;

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            a = get_next(prev);
            people.erase(a);
            cout << a+1 << " ";
            prev = a;
        }
        cout << "\n";
    }

    return 0;
}

