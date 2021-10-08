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
const ll MAXN = 1001;

vi A;

bool valid[MAXN][MAXN] = {0};
bool lose[MAXN][MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;

    cin >> n >> k >> q;
    assert(n <= MAXN);
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }

    rep(c1,0,n){
        int F[MAXN] = {0};
        int dist = 0;
        rep(c2,c1,n){
            F[A[c2]]++;
            if(F[A[c2]] == 1)dist++;
            valid[c1][c2] = (dist == k);
        }
    }

    for(int c1 = n-1; c1 >= 0; c1--){
        for(int c2 = c1; c2 < n; c2++){
            if(valid[c1][c2]){
                lose[c1][c2] = !(lose[c1+1][c2] || lose[c1][c2-1]);
            }
        }
    }

    rep(c1,0,q){
        cin >> a >> b;
        a--;
        b--;
        if(!valid[a][b]){
            cout << "0\n";
        }
        else{
            cout << lose[a][b]+1 << "\n";
        }
    }

    return 0;
}

